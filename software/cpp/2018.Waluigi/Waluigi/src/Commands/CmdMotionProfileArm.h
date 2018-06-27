#ifndef CmdMotionProfileArm_H
#define CmdMotionProfileArm_H

#include <string>
#include "Commands/Command.h"
#include "../Robot.h"
// ??? // #include "Autonomous/AutonomousSelector.h"
#include "../Custom/MotionProfileData.h"
#include "../Custom/MotionProfileControl.h"

class CmdMotionProfileArm : public Command {
public:
	CmdMotionProfileArm(std::string profile, int profileTimeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	MotionProfileControl MPController;
	std::string _profile;
};

#endif  // CmdMotionProfileArm_H
