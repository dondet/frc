#ifndef SubCameraPID_H
#define SubCameraPID_H

#include <Commands/PIDSubsystem.h>
#include <Custom/PIDObjects/CameraXPIDOutput.h>
#include <Custom/PIDObjects/CameraXPIDSource.h>
#include <Custom/PIDObjects/CameraYPIDOutput.h>
#include <Custom/PIDObjects/CameraYPIDSource.h>

class SubCameraPID : public PIDSubsystem {
public:
	SubCameraPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

private:
	double p;
	double i;
	double d;

	std::shared_ptr<frc::PIDController> cameraXController;
	std::shared_ptr<frc::PIDController> cameraYController;
	std::shared_ptr<CameraXPIDSource> cameraXSource;
	std::shared_ptr<CameraXPIDOutput> cameraXOutput;
	std::shared_ptr<CameraXPIDSource> cameraYSource;
	std::shared_ptr<CameraXPIDOutput> cameraYOutput;

};

#endif  // SubCameraPID_H
