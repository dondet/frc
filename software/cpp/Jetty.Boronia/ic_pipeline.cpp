#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "GripPipeline.h"
#include <ctime>
#include <iostream>
#include <fstream>

#include <chrono>
#include <cstdio>
#include <thread>
#include "ntcore.h"

#include "networktables/NetworkTable.h"

using namespace cv;
using namespace std;

RNG rng(12345);
int peg_hits = 0;
int peg_misses = 0;
int debug = 0;

int main( int argc, char *argv[] )
{

  // handle command line arguments
  if( ( argc > 1 ) && ( strcmp( argv[1], "--debug" ) == 0 ) )
    debug = 1;

  // setup image pipeline
  cv::Mat img;
  grip::GripPipeline ic_pipeline;
  cv::VideoCapture input(0);

  // record start time
  clock_t start = clock();

  // setup network tables connection
  auto nt = NetworkTable::GetTable("JETSON");
  nt->SetClientMode();
  nt->SetIPAddress("10.55.84.41\n");
  nt->Initialize();
  std::this_thread::sleep_for(std::chrono::seconds(5));

  for (;;)
  {

    // STEP 1: fetch image
    if(!input.read(img))
      break;

    // STEP 2: setup image pipeline
    ic_pipeline.setsource0(img);
    ic_pipeline.process(img);

    // STEP 3: obtain intermediate images and countour vectors
    cv::Mat* img_hsvthreshold = ic_pipeline.gethsvThresholdOutput();
    cv::Mat* img_blur = ic_pipeline.getblurOutput();
    // std::vector<std::vector<cv::Point> >* img_findcontours = ic_pipeline.getfindContoursOutput();
    std::vector<std::vector<cv::Point> >* img_filtercontours = ic_pipeline.getfilterContoursOutput();

    // STEP 4: output contour x, y, width and height
    cout << "INFO: bounding rectangles for each contour: (x,y):(width,height)" << endl;
    for (std::vector<cv::Point> contour: *img_filtercontours)
    {
      cv::Rect br = boundingRect(contour);
      cout << "(" << br.x << "," << br.y << "):(" << br.width << "," << br.height << ")" << endl;
    }

    // STEP 5: construct image to display filetered contours, bounding rectangles and origins of rectangles
    cv::Mat img_contours = cv::Mat::zeros( img.size(), CV_8UC3 );
    for( size_t i = 0; i< img_filtercontours->size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( img_contours, *img_filtercontours, (int)i, color, 2, 8 );
     }
    int contourcount = 0;
    int min_x = 1000000;
    int max_x = 0;
    int min_y = 1000000;
    int max_y = 0;
    int peg_x = -999999;
    int peg_y = -999999;
    for (std::vector<cv::Point> contour: *img_filtercontours)
    {
      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
      cv::Rect br = boundingRect(contour);
      cv::rectangle( img_contours, br, color, 2, 8 );
      Point origin;
      origin.x = br.x;
      origin.y = br.y;
      cv::circle( img_contours, origin, 5, color, 2, 8 );
      int topleft_x = br.x;
      int topleft_y = br.y;
      int bottomright_x = br.x + br.width;
      int bottomright_y = br.y + br.height;
      if( topleft_x < min_x ) { min_x = topleft_x; }
      if( topleft_y < min_y ) { min_y = topleft_y; }
      if( bottomright_x > max_x ) { max_x = bottomright_x; }
      if( bottomright_y > max_y ) { max_y = bottomright_y; }
      contourcount++;
    }
    int status;
    if( contourcount == 2 )
    {
      status = 0;
      peg_hits++;
      peg_x = ( min_x + max_x ) / 2;
      peg_y = ( min_y + max_y ) / 2;
      cout << "INFO: estimated peg position: (x,y)" << endl;
      cout << "(" << peg_x << "," << peg_y << ")" << endl;
      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
      Point peg;
      peg.x = peg_x;
      peg.y = peg_y;
      cv::circle( img_contours, peg, 10, color, 2, 8 );
    }
    else
    {
      status = 1;
      peg_misses++;
      peg_x = -999999;
      peg_y = -999999;
      cout << "INFO: unable to detect peg positionn" << endl;
    }
    double peg_hitrate = ( 100.0 * peg_hits ) / ( peg_misses + peg_hits );
    cout << "INFO: peg position detections so far: " << peg_hits << " (" << peg_misses << ") (" << peg_hitrate << "% hitrate)" << endl;
    clock_t now = clock();
    double elapsedsecs = ( now - start ) / (double) CLOCKS_PER_SEC;
    double fps = (double) 1.0 / elapsedsecs;
    start = now;
    cout << "INFO: elapsed seconds since last frame: " << elapsedsecs << endl;
    cout << "INFO: frames per second: " << fps << endl;

    // STEP 6: display images
    if( debug == 1 )
    {
      cv::imshow( "img", img );
      cv::imshow( "hsv threshold", *img_hsvthreshold );
      cv::imshow( "blur", *img_blur );
      cv::imshow( "img_contours", img_contours );
    }

    // STEP 7: update network tables
    cout << "INFO: updating network tables" << endl;
    nt->PutNumber( "status", status );
    nt->PutNumber( "timestamp", (int)now );
    nt->PutNumber( "pegx", peg_x );
    nt->PutNumber( "pegy", peg_y );
    nt->PutNumber( "hitrate", peg_hitrate );
    nt->PutNumber( "elapsedsecs", elapsedsecs );
    nt->PutNumber( "fps", fps );
    cout << "-----" << endl;

    // STEP 8: check for control file
    string line;
    ifstream ctlfile("ic_pipeline.stop");
    int running = 1; 
    if( ctlfile.is_open() )
    {
      running = 0;
      ctlfile.close();
    }
    if( running == 0 )
    {
      cout << "INFO: detected control file (stop)" << endl;
      break;
    }

    // STEP 9: check for user request to terminate
    char c = cv::waitKey(30);
    if ( c == ' ' )
      break;

  }

}

