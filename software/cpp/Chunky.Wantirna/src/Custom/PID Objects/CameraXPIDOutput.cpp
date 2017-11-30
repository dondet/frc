/*
 * CameraPIDOutput.cpp
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */


#include <Custom/PID Objects/CameraXPIDOutput.h>
#include "../../Robot.h"
#include "../../Subsystems/subCamera.h"

CameraXPIDOutput::CameraXPIDOutput(double arg_power) {
	power = arg_power;
}

void CameraXPIDOutput::PIDWrite(double output) {
	Robot::subCamera->Pan(power);
}

CameraXPIDOutput::~CameraXPIDOutput() {

}


