#include "SubEncodedArmLift.h"
#include "../RobotMap.h"

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "Constants.h"

SubEncodedArmLift::SubEncodedArmLift() : Subsystem("ExampleSubsystem") {

	TWO = 1;
	THREE = 1;
	FOUR = 1;

	_talon = RobotMap::subEncodedArmLiftSrxMaster;
	_prefs = Preferences::GetInstance();

	targetPositionRotations = 0.0;

}

void SubEncodedArmLift::ArmToGroundPos() {  //Button 10

	frc::SmartDashboard::PutNumber("Ground", TWO);
    TWO++;

	//targetPositionRotations = (_prefs->GetDouble("Ground Position", 0.0))*4096;
	targetPositionRotations = 0.0;
	_talon->Set(ControlMode::Position, targetPositionRotations);


}

void SubEncodedArmLift::ArmToSwitchPos() {  //Button 11

	frc::SmartDashboard::PutNumber("Switch", THREE);
	THREE++;


	//targetPositionRotations = (_prefs->GetDouble("Switch Position", 0.0))*4096;
	targetPositionRotations = 0.0;
	_talon->Set(ControlMode::Position, targetPositionRotations);



}

void SubEncodedArmLift::ArmToScalePos() {  //Button 12

	frc::SmartDashboard::PutNumber("Scale", FOUR);
    FOUR++;

	//targetPositionRotations = (_prefs->GetDouble("Scale Position", 0.0))*4096;
//	targetPositionRotations = 2.0 * 4096;
	targetPositionRotations = 2048;
	_talon->Set(ControlMode::Position, targetPositionRotations);



}

void SubEncodedArmLift::Periodic() {

//	frc::SmartDashboard::PutNumber("_talon current /start position", 555);
	absolutePosition = _talon->GetSelectedSensorPosition(0) & 0xFFF;
	if (++_loops >= 40) {
		frc::SmartDashboard::PutNumber("_talon current /start position", absolutePosition);
		_loops = 0;
	}

}

void SubEncodedArmLift::InitDefaultCommand() {


}

// Put methods for controlling this subsystem
// here. Call these from Commands.
