/*
 * CameraXPIDSource.h
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#ifndef SRC_CUSTOM_CAMERAPIDSOURCE_H_
#define SRC_CUSTOM_CAMERAPIDSOURCE_H_
#include "PIDSource.h"

class CameraXPIDSource: public frc::PIDSource {

public:
	CameraXPIDSource();
	virtual ~CameraXPIDSource();
	virtual double PIDGet();
private:

};

#endif /* SRC_CUSTOM_CAMERAPIDSOURCE_H_ */









