// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SUBDRIVEBASE_H
#define SUBDRIVEBASE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANTalon.h"
#include <ADXRs450_gyro.h>

/**
 *
 *
 * @author ExampleAuthor
 */
class SubDriveBase: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> tnxFrontLeft;
	std::shared_ptr<CANTalon> tnxRearLeft;
	std::shared_ptr<CANTalon> tnxFrontRight;
	std::shared_ptr<CANTalon> tnxRearRight;
	std::shared_ptr<RobotDrive> robotDriveFour;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<ADXRS450_Gyro> gyro;

public:
	SubDriveBase();
	void InitDefaultCommand();
	void TakeJoystickInputs( std::shared_ptr<Joystick> stick );
	void Drive( double direction, double power );
	double GetAngle();
	void Stop();
	void ResetAngle();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
