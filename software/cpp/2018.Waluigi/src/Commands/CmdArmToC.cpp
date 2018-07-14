#include "CmdArmToC.h"

CmdArmToC::CmdArmToC() {
	Requires(Robot::subEncodedArm.get());
}

// Called just before this Command runs the first time
void CmdArmToC::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdArmToC::Execute() {
	Robot::subEncodedArm->ArmMoveTo("C");
}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmToC::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmToC::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmToC::Interrupted() {
	End();
}
