/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CmdLeftSwitchLeft.h"
#include "CmdAutoDrive.h"
#include "CmdAutoTurn.h"
#include "CmdArmBackMid.h"
#include "CmdSpit.h"
#include "CmdArmFront.h"

CmdLeftSwitchLeft::CmdLeftSwitchLeft() {

	AddParallel(new CmdArmBackMid());
	AddSequential(new CmdAutoDrive(4, 0));
	AddSequential(new CmdAutoTurn(90));
	AddSequential(new CmdAutoDrive(0.5, 90));
	AddSequential(new CmdSpit(true), 0.5);
	AddSequential(new CmdArmFront());


}
