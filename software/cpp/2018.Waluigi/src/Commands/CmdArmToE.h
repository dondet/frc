#ifndef CmdArmToE_H
#define CmdArmToE_H

//#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <Commands/Command.h>

class CmdArmToE : public frc::Command {
public:
	CmdArmToE();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // CmdArmToE
