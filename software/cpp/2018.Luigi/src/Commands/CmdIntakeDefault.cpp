#include "CmdIntakeDefault.h"

CmdIntakeDefault::CmdIntakeDefault() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::subIntake.get());
}

// Called just before this Command runs the first time
void CmdIntakeDefault::Initialize() {



}

// Called repeatedly when this Command is scheduled to run
void CmdIntakeDefault::Execute() {

	Robot::subIntake->Stop();

}

// Make this return true when this Command no longer needs to run execute()
bool CmdIntakeDefault::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CmdIntakeDefault::End() {

	Robot::subIntake->FingerStop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdIntakeDefault::Interrupted() {

}
