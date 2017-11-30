#include "subCameraPID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/cmdCameraTrack.h"

#include "../RobotMap.h"

subCameraPID::subCameraPID() : PIDSubsystem("subCameraPID", 1.0, 0.0, 0.0) {
	// Setup PID controller:

	CameraXController = new PIDController*(p,i,d,
										   new CameraXPIDSource(),
										   new CameraXPIDOutput(0)
										   );
	CameraXController.SetInputRange(-1,1);
	CameraXController.SetSetpoint(0);
	CameraXController.SetOutputRange(-1,1);
	CameraXController.Enable();

	CameraYController = new PIDController*(p,i,d, static_cast<PIDSource*>( new CameraYPIDSource()), static_cast<PIDOutput*>( new CameraYPIDOutput(0)));
	CameraYController.SetInputRange(-1,1);
	CameraYController.SetSetpoint(0);
	CameraYController.SetOutputRange(-1,1);
	CameraYController.Enable();
}

double subCameraPID::ReturnPIDInput() {
	// Return input values for the PID loop, Peg X and Y.
	return Robot::subDriveBase->GetPegX();
}

void subCameraPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Robot::subCamera->Pan(output);
}

void subCameraPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CmdCameraTrack());

}
