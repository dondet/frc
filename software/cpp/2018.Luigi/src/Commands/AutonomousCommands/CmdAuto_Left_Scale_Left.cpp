#include "CmdAuto_Left_Scale_Left.h"
#include "Commands/CmdOutput.h"
#include "CmdAuto_MotionProfile.h"
#include "CmdAuto_DeployArmToScale.h"

CmdAuto_Left_Scale_Left::CmdAuto_Left_Scale_Left() {
	/*
	 * From the left starting position, put a cube in the left side of the scale
	 */

	AddParallel(new CmdAuto_DeployArmToScale(6.5));
	AddSequential(new CmdAuto_MotionProfile("Left-Scale-Left", 10));
	AddSequential(new CmdOutput(1, 1));
}