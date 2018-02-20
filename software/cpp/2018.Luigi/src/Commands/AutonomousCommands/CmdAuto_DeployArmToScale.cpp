#include "CmdAuto_DeployArmToScale.h"
#include "Commands/CmdArmPosScale.h"
#include "Commands/CmdArmPosSwitch.h"
#include "CmdAuto_Wait.h"
#include "Commands/CmdIntake.h"

CmdAuto_DeployArmToScale::CmdAuto_DeployArmToScale(double offsetTime) {

	/*
	 * Deploy arm to switch position for driving, then after a number of
	 * seconds equal to offsetTime, move the arm to the scale position.
	 */

	AddParallel(new CmdArmPosSwitch());									//Deploy arm with cube
	AddSequential(new CmdAuto_Wait(offsetTime));
	AddSequential(new CmdArmPosScale());

}
