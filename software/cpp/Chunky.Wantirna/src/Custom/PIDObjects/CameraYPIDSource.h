/*
 * CameraYPIDSource.h
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#ifndef SRC_CUSTOM_PIDOBJECTS_CAMERAYPIDSOURCE_H_
#define SRC_CUSTOM_PIDOBJECTS_CAMERAYPIDSOURCE_H_
#include "PIDSource.h"

class CameraYPIDSource: public frc::PIDSource {

public:
	CameraYPIDSource();
	virtual ~CameraYPIDSource();
	virtual double PIDGet();

private:

};
#endif /* SRC_CUSTOM_PIDOBJECTS_CAMERAYPIDSOURCE_H_ */
