#ifndef CmdArmToD_H
#define CmdArmToD_H

//#include "Commands/Subsystem.h"
#include "../Robot.h"
#include <Commands/Command.h>

class CmdArmToD : public frc::Command {
public:
	CmdArmToD();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif  // CmdArmToD
