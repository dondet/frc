// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "CmdAutonomous.h"
#include "Commands/CmdLaunchFuel.h"
#include "Commands/CmdAutoDrive.h"
#include "Commands/CmdAutoTurn.h"
#include "Commands/CmdAutoDriveToPeg.h"
#include "Commands/CmdAutoMotorTest.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

CmdAutonomous::CmdAutonomous() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	/* Add Commands here:
    e.g. AddSequential(new Command1());
         AddSequential(new Command2());
    these will run in order.

    To run multiple commands at the same time, use AddParallel()
    e.g. AddParallel(new Command1());
         AddSequential(new Command2());
    Command1 and Command2 will run in parallel.

    A command group will require all of the subsystems that each member
    would require.
    e.g. if Command1 requires chassis, and Command2 requires arm,
    a CommandGroup containing them would require both the chassis and the
    arm. */

	//Auto 1: Drive straight to peg from middle
	//AddSequential(new CmdAutoDrive(-0.4, 0, 2.25));

	//Auto 2: Turn from right hand side to peg
	//AddSequential(new CmdAutoDrive(-0.4, 0.2, 2));
	//AddSequential(new CmdAutoDriveToPeg());
	//AddSequential(new CmdAutoDrive(-0.2, 0, 1));

	//Auto 3: Turn from left hand side to peg
	//AddSequential(new CmdAutoDrive(0.2, -0.2, 2));
	//AddSequential(new CmdAutoDriveToPeg());
	//AddSequential(new CmdAutoDrive(0.2, 0, 1));

	//AutoTesting:
	//AddSequential(new CmdTurnToPeg());

              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
