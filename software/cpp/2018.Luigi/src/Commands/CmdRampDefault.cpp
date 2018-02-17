#include "CmdRampDefault.h"

CmdRampDefault::CmdRampDefault() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::subRamp.get());
	Requires(Robot::subEncodedArmLift.get());
}

// Called just before this Command runs the first time
void CmdRampDefault::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdRampDefault::Execute() {

	sticky_3 = Robot::oi->getJoystick0();
	_POV = sticky_3->GetPOV();

	if (135 <= _POV && _POV <= 225) { //bottom half of POV
//		CmdPrepForClimb *cmdPrepForClimbPtr;
//		cmdPrepForClimbPtr = new CmdPrepForClimb;
//		cmdPrepForClimbPtr->Start();

		Robot::subEncodedArmLift->ArmToScalePos();
		_rampCase = 1;

		}

	if (270 <= _POV or (_POV <= 90 && _POV >= 0) ){ //top half of POV
		SetTimeout(0.15);
		Robot::subRamp->ResetRamp();
	}

	switch(_rampCase){
	case 0 :
	break;
	case 1 :
		if (Robot::subEncodedArmLift->ReachedPosition()) {
			SetTimeout(0.5);
			Robot::subRamp->DropRamp();
		}
	break;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool CmdRampDefault::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void CmdRampDefault::End() {
	Robot::subRamp->StopRamp();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdRampDefault::Interrupted() {

}
