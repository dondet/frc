#ifndef CmdArmToB_H
#define CmdArmToB_H

//#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <Commands/Command.h>

class CmdArmToB : public frc::Command {
public:
	CmdArmToB();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // CmdArmToB
