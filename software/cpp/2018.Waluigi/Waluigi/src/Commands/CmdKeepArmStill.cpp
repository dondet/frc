/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CmdKeepArmStill.h"
#include "../Robot.h"
#include <iostream>

CmdKeepArmStill::CmdKeepArmStill() {
	Requires(Robot::subEncodedArm.get());
	feedForward = ( (weight * dist) / (gearRatio * (stallTorque/maxVoltage)) );
}

// Called just before this Command runs the first time
void CmdKeepArmStill::Initialize() {
	std::cout << "init CmdKeepArmStill" << std::endl;
	std::cout << "CmdKeepArmStill name: " << this->GetName() << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void CmdKeepArmStill::Execute() {
	double currentAngle = Robot::subEncodedArm->GetArmAngle();
	double additionalVoltage = feedForward * cos(currentAngle);
	double additionalSpeed = additionalVoltage/maxVoltage;
	SmartDashboard::PutNumber("armSpeed", additionalSpeed);
	SmartDashboard::PutNumber("encoderPosition", currentAngle);
	Robot::subEncodedArm->VoltageControl(additionalSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdKeepArmStill::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdKeepArmStill::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdKeepArmStill::Interrupted() {

}
