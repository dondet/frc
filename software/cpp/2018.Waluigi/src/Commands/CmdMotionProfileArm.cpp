#include "CmdMotionProfileArm.h"

const std::string suffix = "main";

CmdMotionProfileArm::CmdMotionProfileArm(std::string profile, int profileTimeout) : MPController(RobotMap::subEncodedArmTnx, profile, suffix, profileTimeout)
{
	std::cout << "CmdMotionProfileArm: Constructor Start (" << profile << ")" << std::endl;
	_profile = profile;
	Requires(Robot::subEncodedArm.get());
	std::cout << "CmdMotionProfileArm: Constructor Finish (" << profile << ")" << std::endl;
}

// Called just before this Command runs the first time
void CmdMotionProfileArm::Initialize() {
	std::cout << "Cmd_MotionProfileArm: Initialise Start (" << _profile << ")" << std::endl;
	std::cout << "CmdMotionProfileArm: Loading MP" << std::endl;
	MPController.load();
	std::cout << "CmdMotionProfileArm: Driving MP" << std::endl;
	//Initialise MPController
	MPController.initialise();
	std::cout << "CmdMotionProfileArm: Initialise Finish (" << _profile << ")" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void CmdMotionProfileArm::Execute() {
	MPController.execute();
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMotionProfileArm::IsFinished() {
	if (not MPController.IsRunning()){
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void CmdMotionProfileArm::End() {
	MPController.stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMotionProfileArm::Interrupted() {
	End();
}
