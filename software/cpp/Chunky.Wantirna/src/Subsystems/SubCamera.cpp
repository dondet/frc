#include "SubCamera.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/CmdCameraTrack.h"
#include "../Commands/CmdCameraManual.h"
#include "CANTalon.h"
#include "SmartDashboard/SmartDashboard.h"
#include <PIDController.h>

SubCamera::SubCamera() : Subsystem("SubCamera") {

	p = 0.0;
	i = 0.0;
	d = 0.0;

	//my setup...
	myP = 0.0;
	myI = 0.0;
	myD = 0.0;

	//Setup motors
	SpkCameraHorizontal = RobotMap::subCameraHorizontal;
	SpkCameraVirtical = RobotMap::subCameraVirtical;


    //Setup PID Controllers


	cameraXSource = std::make_shared<CameraXPIDSource>();
	cameraXOutput = std::make_shared<CameraXPIDOutput>(0);

	cameraXController = std::make_shared<frc::PIDController>(myP, myI, myD,
			static_cast<frc::PIDSource*>(cameraXSource.get()),
			static_cast<frc::PIDOutput*>(cameraXOutput.get()));

	cameraXController->SetInputRange(-1, 1);
	cameraXController->SetSetpoint(0);
	cameraXController->SetOutputRange(-1, 1);

	cameraYSource = std::make_shared<CameraXPIDSource>();
	cameraYOutput = std::make_shared<CameraXPIDOutput>(0);

	cameraYController = std::make_shared<frc::PIDController>(myP, myI, myD,
			static_cast<frc::PIDSource*>(cameraYSource.get()),
			static_cast<frc::PIDOutput*>(cameraYOutput.get()));

	cameraYController->SetInputRange(-1, 1);
	cameraYController->SetSetpoint(0);
	cameraYController->SetOutputRange(-1, 1);
}

void SubCamera::InitDefaultCommand() {
	//Set Default Command
	SetDefaultCommand(new CmdCameraManual());
}

void SubCamera::Pan(double speed) {
	//Run panning motor at set speed
	SpkCameraHorizontal->Set(-speed/1.5);
}

void SubCamera::Tilt(double speed) {
	//Run tilting motor at set speed
	SpkCameraVirtical->Set(-speed/1.5);
}

void SubCamera::PIDControl(){
	//Start PID control
	cameraXController->Enable();
	cameraYController->Enable();
}

void SubCamera::SetPID( double p, double i, double d ) {
	myP = p;
	myI = i;
	myD = d;
	//SmartDashboard::PutNumber("MyP:", myP);
	//SmartDashboard::PutNumber("MyI:", myI);
	//SmartDashboard::PutNumber("MyD:", myD);
}

void SubCamera::Stop(){
	//Disable PID Control
	cameraXController->Disable();
	cameraYController->Disable();

	//Stop both pan and tilt motors
	SpkCameraVirtical->Set(0);
	SpkCameraHorizontal->Set(0);
}

void SubCamera::PublishValues(){
	std::shared_ptr<Joystick> stick = Robot::oi->getJoystick1();
	SmartDashboard::PutNumber("Joystick Axis 2: Pan", stick->GetRawAxis(4));
	SmartDashboard::PutNumber("Joystick Axis 5: Tilt", stick->GetRawAxis(5));

}
