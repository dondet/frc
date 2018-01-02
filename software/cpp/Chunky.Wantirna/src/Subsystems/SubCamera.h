#ifndef SubCamera_H
#define SubCamera_H
#include "NetworkTables/NetworkTable.h"
#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "CANTalon.h"
#include <Custom/PIDObjects/CameraXPIDOutput.h>
#include <Custom/PIDObjects/CameraXPIDSource.h>
#include <Custom/PIDObjects/CameraYPIDOutput.h>
#include <Custom/PIDObjects/CameraYPIDSource.h>

class SubCamera : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> SpkCameraHorizontal;
	std::shared_ptr<SpeedController> SpkCameraVirtical;
	std::shared_ptr<Preferences> prefs;

	//PID Things
	double p;
	double i;
	double d;
	double myP;
	double myI;
	double myD;
	std::shared_ptr<frc::PIDController> cameraXController;
	std::shared_ptr<frc::PIDController> cameraYController;
	std::shared_ptr<CameraXPIDSource> cameraXSource;
	std::shared_ptr<CameraXPIDOutput> cameraXOutput;
	std::shared_ptr<CameraYPIDSource> cameraYSource;
	std::shared_ptr<CameraYPIDOutput> cameraYOutput;


public:
	SubCamera();
	void InitDefaultCommand();
	void Pan(double);
	void Tilt(double);
	void PIDControl();
	void Stop();
	void PublishValues();
	double* GetPreferences();
	void SetPID(double, double, double );
};

#endif  // SubCamera_H
