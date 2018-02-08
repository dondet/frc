#include "CmdArmPosScale.h"

CmdArmPosScale::CmdArmPosScale() {

	Requires(Robot::subEncodedArmLift.get());

}

// Called just before this Command runs the first time
void CmdArmPosScale::Initialize() {

	std::cout << "Moving arm to scale" << std::endl;

}

// Called repeatedly when this Command is scheduled to run
void CmdArmPosScale::Execute() {

	Robot::subEncodedArmLift->ArmToScalePos();

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
