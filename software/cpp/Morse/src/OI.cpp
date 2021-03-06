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
// #include "Commands/AutonomousCommand.h"
#include "Commands/CmdAutoGearPusherDoorOpen.h"
#include "Commands/CmdAutoGearPusherOut.h"
#include "Commands/CmdAutoGearPusherReset.h"
#include "Commands/CmdAutoNudgeForward.h"
#include "Commands/CmdClimb.h"
#include "Commands/CmdDeployGear.h"
#include "Commands/CmdDriveAwayFromPeg.h"
#include "Commands/CmdDriveToPeg.h"
#include "Commands/CmdDriveToPegLittle.h"
#include "Commands/CmdGearPusher.h"
#include "Commands/CmdGearPusherDoor.h"
#include "Commands/CmdGrpMidPeg.h"
#include "Commands/CmdJoystickDrive.h"
#include "Commands/CmdSideBaseline.h"
#include "Commands/cmdAutonomousSelector.h"
#include "Commands/CmdGearIntake.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    joystick.reset(new Joystick(0));
    
    btnClimber.reset(new JoystickButton(joystick.get(), 3));
    btnClimber->WhileHeld(new CmdClimb());
    btnGearPusherDoor.reset(new JoystickButton(joystick.get(), 2));
    btnGearPusherDoor->WhileHeld(new CmdGearPusherDoor());
    btnGearPusher.reset(new JoystickButton(joystick.get(), 1));
    btnGearPusher->WhileHeld(new CmdGearPusher());
    btnGearPickup.reset(new JoystickButton(joystick.get(), 4));
    btnGearPickup->WhileHeld(new CmdGearIntake());

    // SmartDashboard Buttons
    SmartDashboard::PutData("CmdSideBaseline", new CmdSideBaseline());
    SmartDashboard::PutData("cmdAutonomousSelector", new cmdAutonomousSelector());
    SmartDashboard::PutData("CmdAutoGearPusherOut", new CmdAutoGearPusherOut());
    SmartDashboard::PutData("CmdAutoGearPusherReset", new CmdAutoGearPusherReset());
    SmartDashboard::PutData("CmdAutoGearPusherDoorOpen", new CmdAutoGearPusherDoorOpen());
    SmartDashboard::PutData("CmdAutoNudgeForward: Default", new CmdAutoNudgeForward());
    SmartDashboard::PutData("CmdDriveToPegLittle", new CmdDriveToPegLittle());
    SmartDashboard::PutData("CmdDeployGear", new CmdDeployGear());
    SmartDashboard::PutData("CmdDriveAwayFromPeg", new CmdDriveAwayFromPeg());
    SmartDashboard::PutData("CmdDriveToPeg: execounter", new CmdDriveToPeg());
    SmartDashboard::PutData("CmdGrpMidPeg", new CmdGrpMidPeg());
    SmartDashboard::PutData("CmdClimb", new CmdClimb());
    SmartDashboard::PutData("CmdJoystickDrive", new CmdJoystickDrive());
    SmartDashboard::PutData("CmdGearPusherDoor", new CmdGearPusherDoor());
    SmartDashboard::PutData("CmdGearPusher", new CmdGearPusher());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getJoystick() {
   return joystick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
