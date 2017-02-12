// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/CmdAutoDrive.h"
#include "Commands/CmdAutoMotorTest.h"
#include "Commands/CmdAutonomous.h"
#include "Commands/CmdChunder.h"
#include "Commands/CmdClimb.h"
#include "Commands/CmdFeedMe.h"
#include "Commands/CmdIntakeDeploy.h"
#include "Commands/CmdIntakeRollerIn.h"
#include "Commands/CmdJoystickDrive.h"
#include "Commands/CmdLaunchFuel.h"
#include "Commands/CmdMoveServo.h"
#include "Commands/CmdSliderOut.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick1.reset(new Joystick(0));
    
    btnChunder.reset(new JoystickButton(joystick1.get(), 9));
    btnChunder->WhileHeld(new CmdChunder());
    btnFeedMe.reset(new JoystickButton(joystick1.get(), 10));
    btnFeedMe->WhileHeld(new CmdFeedMe());
    btnLaunchFuel.reset(new JoystickButton(joystick1.get(), 12));
    btnLaunchFuel->WhileHeld(new CmdLaunchFuel());
    btnClimb.reset(new JoystickButton(joystick1.get(), 2));
    btnClimb->WhileHeld(new CmdClimb());
    btnMoveServo.reset(new JoystickButton(joystick1.get(), 1));
    btnMoveServo->WhileHeld(new CmdMoveServo());

    // SmartDashboard Buttons
    SmartDashboard::PutData("CmdChunder", new CmdChunder());
    SmartDashboard::PutData("CmdFeedMe", new CmdFeedMe());
    SmartDashboard::PutData("CmdIntakeDeploy", new CmdIntakeDeploy());
    SmartDashboard::PutData("CmdSliderOut", new CmdSliderOut());
    SmartDashboard::PutData("CmdIntakeRollerIn", new CmdIntakeRollerIn());
    SmartDashboard::PutData("CmdAutoMotorTest", new CmdAutoMotorTest());
    SmartDashboard::PutData("CmdAutonomous", new CmdAutonomous());
    SmartDashboard::PutData("CmdAutoDrive", new CmdAutoDrive(0,0,0));
    SmartDashboard::PutData("CmdLaunchFuel", new CmdLaunchFuel());
    SmartDashboard::PutData("CmdClimb", new CmdClimb());
    SmartDashboard::PutData("CmdMoveServo", new CmdMoveServo());
    SmartDashboard::PutData("CmdJoystickDrive", new CmdJoystickDrive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getJoystick1() {
   return joystick1;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
