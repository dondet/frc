#ifndef SRC_MOTIONPROFILEDATA_H_
#define SRC_MOTIONPROFILEDATA_H_

#include <vector>
#include "CSV.h"
#include <ctre/Phoenix.h>


class MotionProfileData {
public:

	MotionProfileData( std::string S0 );
	MotionProfileData( std::string S0, std::string S1 );
	void ReadCSV(int set, std::string fileName);
	void ReadMotionProfile(std::string MP);
    int GetNumberOfPoints();
    double GetPosition( int set, int number);
    double GetVelocity( int set, int number);
    double GetDuration( int set, int number);
    TrajectoryDuration ConvertDuration(double dur);
    TrajectoryPoint GetPoint(int set, int number);
    std::vector<std::vector<TrajectoryPoint>> sets;
	int mpSize;
	int channels;
	std::string suffixA;
	std::string suffixB;

};

#endif /* SRC_MOTIONPROFILEDATA_H_ */
