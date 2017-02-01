// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CmdLaunchFuel.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

CmdLaunchFuel::CmdLaunchFuel(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::subShooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void CmdLaunchFuel::Initialize() {
	Robot::subShooter->Run();
}

// Called repeatedly when this Command is scheduled to run
void CmdLaunchFuel::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CmdLaunchFuel::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void CmdLaunchFuel::End() {
	Robot::subShooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdLaunchFuel::Interrupted() {
	End();
}
