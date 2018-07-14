#include "CmdArmToE.h"

CmdArmToE::CmdArmToE() {
	Requires(Robot::subEncodedArm.get());
}

// Called just before this Command runs the first time
void CmdArmToE::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdArmToE::Execute() {
	Robot::subEncodedArm->ArmMoveTo("E");
}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmToE::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmToE::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmToE::Interrupted() {
	End();
}
