#ifndef subCameraPID_H
#define subCameraPID_H

#include <Commands/PIDSubsystem.h>

class subCameraPID : public PIDSubsystem {
public:
	subCameraPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

private:

	double p;
	double i;
	double d;

	frc::PIDController CameraXController;
	frc::PIDController CameraYController;

};

#endif  // subCameraPID_H
