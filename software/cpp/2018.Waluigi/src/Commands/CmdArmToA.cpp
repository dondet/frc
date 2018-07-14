#include "CmdArmToA.h"

CmdArmToA::CmdArmToA() {
	Requires(Robot::subEncodedArm.get());
}

// Called just before this Command runs the first time
void CmdArmToA::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdArmToA::Execute() {
	Robot::subEncodedArm->ArmMoveTo("A");
}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmToA::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmToA::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmToA::Interrupted() {
	End();
}
