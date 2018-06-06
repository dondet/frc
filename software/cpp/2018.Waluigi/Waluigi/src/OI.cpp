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
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/CmdJoyStickDrive.h"
#include "Commands/CmdSuck.h"
#include "Commands/CmdSpit.h"

OI::OI() {
    joystick.reset(new frc::Joystick(0));
    

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("CmdJoyStickDrive", new CmdJoyStickDrive());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    //Intake
    btnSucker.reset(new JoystickButton(joystick.get(), 5));
    btnSucker->WhileHeld(new CmdSuck());
    btnSpitter.reset(new JoystickButton(joystick.get(), 6));
    btnSpitter->WhileHeld(new CmdSpit());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getJoystick() {
   return joystick;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
