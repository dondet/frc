/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class SubVisionProcessor : public frc::Subsystem {

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	static void VisionThread();
	SubVisionProcessor();
	void InitDefaultCommand() override;
	std::thread * _visionThreadPtr;

public:

};
