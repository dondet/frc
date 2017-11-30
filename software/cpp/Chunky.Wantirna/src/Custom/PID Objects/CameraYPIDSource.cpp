/*
 * CameraYPIDSource.cpp
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#include <Custom/PID Objects/CameraYPIDSource.h>
#include "../../Robot.h"

CameraYPIDSource::CameraYPIDSource() {

}

CameraYPIDSource::~CameraYPIDSource() {

}


double CameraYPIDSource::PIDGet() {
	return Robot::subDriveBase->GetPegY();
}
