#include <Custom/PIDObjects/CameraXPIDSource.h>
#include "../../Robot.h"

CameraXPIDSource::CameraXPIDSource() {

}

CameraXPIDSource::~CameraXPIDSource(){

}

double CameraXPIDSource::PIDGet() {
	return Robot::subDriveBase->GetPegX();
}
