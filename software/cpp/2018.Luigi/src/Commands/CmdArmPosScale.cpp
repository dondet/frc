#include "CmdArmPosScale.h"

CmdArmPosScale::CmdArmPosScale() {

	Requires(Robot::subEncodedArmLift.get());

}

// Called just before this Command runs the first time
void CmdArmPosScale::Initialize() {

	Robot::subEncodedArmLift->ArmToScalePos();

}

// Called repeatedly when this Command is scheduled to run
void CmdArmPosScale::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmPosScale::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmPosScale::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmPosScale::Interrupted() {

}