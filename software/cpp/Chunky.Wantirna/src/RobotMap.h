// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"
#include "CANTalon.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<SpeedController> subDriveBaseSpeedControllerRight;
	static std::shared_ptr<SpeedController> subDriveBaseSpeedControllerLeft;
	static std::shared_ptr<RobotDrive> subDriveBaseRobotDrive;
	static std::shared_ptr<Servo> subGearCatcherSrvFlap1;
	static std::shared_ptr<Servo> subGearCatcherSrvFlap2;
	static std::shared_ptr<SpeedController> subClimberSpkClimber;
	static std::shared_ptr<CANTalon> subShooterTnxShooterTop;
	static std::shared_ptr<CANTalon> subShooterTnxShooterBottom;
	static std::shared_ptr<CANTalon> subIntakeTnxIntakeRollers;
	static std::shared_ptr<CANTalon> subIntakeTnxIntakeSliders;
	static std::shared_ptr<SpeedController> subFeederVspFeederWheels;
	static std::shared_ptr<SpeedController> subFeederVspAgitatorPaddles;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
