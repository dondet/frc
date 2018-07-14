#ifndef CmdArmToC_H
#define CmdArmToC_H

//#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <Commands/Command.h>

class CmdArmToC : public frc::Command {
public:
	CmdArmToC();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // CmdArmToC
