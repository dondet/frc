#include "CmdArmToD.h"

CmdArmToD::CmdArmToD() {
	Requires(Robot::subEncodedArm.get());
}

// Called just before this Command runs the first time
void CmdArmToD::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdArmToD::Execute() {
	Robot::subEncodedArm->ArmMoveTo("D");
}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmToD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmToD::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmToD::Interrupted() {
	End();
}
