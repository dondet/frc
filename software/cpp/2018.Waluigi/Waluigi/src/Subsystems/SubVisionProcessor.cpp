/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SubVisionProcessor.h"
#include "../RobotMap.h"

SubVisionProcessor::SubVisionProcessor() : Subsystem("SubVisionProcessor") {
	std::thread visionThread(VisionThread);
	visionThread.detach();
}

void SubVisionProcessor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void SubVisionProcessor::VisionThread() {
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
	cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
	cv::Mat source;
	cv::Mat output;
	while(true) {
		cvSink.GrabFrame(source);
		cvtColor(source, output, cv::COLOR_BGR2GRAY);
		outputStreamStd.PutFrame(output);
	}
}
