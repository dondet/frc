/*
 * CameraPIDOutout.h
 *
 *  Created on: 30Nov.,2017
 *      Author: Liam
 */

#ifndef SRC_CUSTOM_PID_OBJECTS_CAMERAXPIDOUTPUT_H_
#define SRC_CUSTOM_PID_OBJECTS_CAMERAXPIDOUTPUT_H_

#include "PIDOutput.h"

class CameraXPIDOutput: public frc::PIDOutput {

public:
	CameraXPIDOutput(double arg_power);
	virtual ~CameraXPIDOutput();
	virtual void PIDWrite(double output);

private:
	double power = 0;
};


#endif /* SRC_CUSTOM_DRIVEPIDOUTPUT_H_ */
