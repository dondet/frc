/*
 * armPID.cpp
 *
 *  Created on: 14 Jul. 2018
 *      Author: Liam
 */

#include "armPID.h"
#include "../Robot.h"

armPID::armPID() {
	feedForward = ( (weight * dist) / (gearRatio * (stallTorque/maxVoltage)) );
}


void armPID::PIDWrite(double output) {

	//Calculate Feedforward
	double currentAngle = Robot::subEncodedArm->GetArmAngle();
	currentAngle = currentAngle*3.1415/180;
	double additionalVoltage = feedForward * sin(currentAngle) * multiplier;
	double additionalSpeed = additionalVoltage/maxVoltage;
	SmartDashboard::PutNumber("armSpeed", additionalSpeed);

	//Run arm motor
	Robot::subEncodedArm->VoltageControl(output + additionalSpeed);
}

armPID::~armPID() {
	// TODO Auto-generated destructor stub
}

