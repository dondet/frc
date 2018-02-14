#include "CmdRampDrop.h"

CmdRampDrop::CmdRampDrop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::subRamp.get());
}

// Called just before this Command runs the first time
void CmdRampDrop::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdRampDrop::Execute() {

	SetTimeout(0.5);
	Robot::subRamp->ResetRamp();

}

// Make this return true when this Command no longer needs to run execute()
bool CmdRampDrop::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void CmdRampDrop::End() {
	Robot::subRamp->StopRamp();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdRampDrop::Interrupted() {

}
