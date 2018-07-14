#include "CmdArmToB.h"

CmdArmToB::CmdArmToB() {
	Requires(Robot::subEncodedArm.get());
}

// Called just before this Command runs the first time
void CmdArmToB::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdArmToB::Execute() {
	Robot::subEncodedArm->ArmMoveTo("B");
}

// Make this return true when this Command no longer needs to run execute()
bool CmdArmToB::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdArmToB::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdArmToB::Interrupted() {
	End();
}
