/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>

class CmdKeepArmStill : public frc::Command {
public:
	CmdKeepArmStill();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:

	double feedForward;

	//Arm constants
	const double dist = 		0.54;	//Meters
	const double weight =		5;		//Kilograms

	//Motor constants
	const double stallTorque = 	1.4;	//Newton Meters
	const double maxVoltage = 	12;		//Volts

	//GearBox constants
	const double gearRatio =	10.5;
};

