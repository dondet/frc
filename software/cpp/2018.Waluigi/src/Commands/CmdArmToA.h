#ifndef CmdArmToA_H
#define CmdArmToA_H

//#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <Commands/Command.h>

class CmdArmToA : public frc::Command {
public:
	CmdArmToA();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // CmdArmToA
