/*
 * CameraYPIDOutput.h
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#ifndef SRC_CUSTOM_PID_OBJECTS_CAMERAYPIDOUTPUT_H_
#define SRC_CUSTOM_PID_OBJECTS_CAMERAYPIDOUTPUT_H_

#include "PIDOutput.h"

class CameraYPIDOutput {
	CameraYPIDOutput(double arg_power);
	virtual ~CameraYPIDOutput();
	virtual void PIDWrite(double output);

private:
	double power = 0;
};

#endif /* SRC_CUSTOM_PID_OBJECTS_CAMERAYPIDOUTPUT_H_ */
