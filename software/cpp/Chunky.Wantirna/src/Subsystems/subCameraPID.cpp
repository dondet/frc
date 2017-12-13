#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <PIDController.h>
#include <Subsystems/SubCameraPID.h>
#include "Commands/cmdCameraTrack.h"

#include "../RobotMap.h"

SubCameraPID::SubCameraPID() :
		PIDSubsystem("subCameraPID", 1.0, 0.0, 0.0) {
	// Setup PID controller:

	p = 1.0;
	i = 1.0;
	d = 1.0;

	cameraXSource = std::make_shared<CameraXPIDSource>();
	cameraXOutput = std::make_shared<CameraXPIDOutput>(0);
	cameraYSource = std::make_shared<CameraXPIDSource>();
	cameraYOutput = std::make_shared<CameraXPIDOutput>(0);

	cameraXController = std::make_shared<frc::PIDController>(1.0, 1.0, 1.0,
			static_cast<frc::PIDSource*>(cameraXSource.get()),
			static_cast<frc::PIDOutput*>(cameraXOutput.get()));

	cameraXController->SetInputRange(-1, 1);
	cameraXController->SetSetpoint(0);
	cameraXController->SetOutputRange(-1, 1);
	cameraXController->Enable();

	cameraYController = std::make_shared<frc::PIDController>(1.0, 1.0, 1.0,
			static_cast<frc::PIDSource*>(cameraYSource.get()),
			static_cast<frc::PIDOutput*>(cameraYOutput.get()));

	cameraYController->SetInputRange(-1, 1);
	cameraYController->SetSetpoint(0);
	cameraYController->SetOutputRange(-1, 1);
	cameraYController->Enable();
}

double SubCameraPID::ReturnPIDInput() {
	// Return input values for the PID loop, Peg X and Y.
	return Robot::subDriveBase->GetPegX();
}

void SubCameraPID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Robot::subCamera->Pan(output);
}

void SubCameraPID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new CmdCameraTrack());

}
