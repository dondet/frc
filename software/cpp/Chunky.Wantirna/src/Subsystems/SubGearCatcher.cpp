// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "WPILib.h"
#include "SubGearCatcher.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

SubGearCatcher::SubGearCatcher() : Subsystem("SubGearCatcher") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    srvFlap1 = RobotMap::subGearCatcherSrvFlap1;
    srvFlap2 = RobotMap::subGearCatcherSrvFlap2;
    angUltrasonicSensor = RobotMap::subGearCatcherAngUltrasonicSensor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    pnuDoors = RobotMap::subGearCatcherPnuDoors;
    pnuPusher = RobotMap::subGearCatcherPnuPusher;

    //Set servos and actuators to default positions
    ServosIn();
    PusherIn();
    DoorsClose();
}

void SubGearCatcher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void SubGearCatcher::SetServos( float position ) {
    srvFlap1->Set( position );
    srvFlap2->Set( position );
}

void SubGearCatcher::ServosOut(){
	srvFlap1->Set(0);
	srvFlap2->Set(0.9);
}


void SubGearCatcher::ServosIn() {
    srvFlap1->Set(0.9);
    srvFlap2->Set(0);
}

void SubGearCatcher::PusherOut() {
	pnuPusher->Set(DoubleSolenoid::kReverse);
}

void SubGearCatcher::PusherIn() {
	pnuPusher->Set(DoubleSolenoid::kForward);
}

void SubGearCatcher::DoorsOpen() {
	pnuDoors->Set(DoubleSolenoid::kForward);
}

void SubGearCatcher::DoorsClose() {
    pnuDoors->Set(DoubleSolenoid::kReverse);
}
