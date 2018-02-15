#ifndef CmdIntakeDefault_H
#define CmdIntakeDefault_H

#include <Commands/Command.h>
#include "Robot.h"

class CmdIntakeDefault : public Command {
public:
	CmdIntakeDefault();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CmdIntakeDefault_H
