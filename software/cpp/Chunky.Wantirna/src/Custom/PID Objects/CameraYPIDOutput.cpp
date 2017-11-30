/*
 * CameraYPIDOutput.cpp
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#include <Custom/PID Objects/CameraYPIDOutput.h>
#include "../../Robot.h"
#include "../../Subsystems/subCamera.h"

CameraYPIDOutput::CameraYPIDOutput(double arg_power) {
	power = arg_power;
}

void CameraYPIDOutput::PIDWrite(double output) {
	Robot::subCamera->Pan(power);
}

CameraYPIDOutput::~CameraYPIDOutput() {

}
