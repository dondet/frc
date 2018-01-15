#include "SubDriveBase.h"
#include "Commands/MyJoystickDrive.h"

SubDriveBase::SubDriveBase() : frc::Subsystem("SubDriveBase") {
    sRXleft = RobotMap::subDriveBaseSRXleft;
    sRXright = RobotMap::subDriveBaseSRXright;
    differentialDrive = RobotMap::subDriveBaseDifferentialDrive;

    ultrasonicInputFront = RobotMap::subDriveBaseUltrasonicInputFront;
    ultrasonicInputRight = RobotMap::subDriveBaseUltrasonicInputRight;
    ultrasonicInputBack = RobotMap::subDriveBaseUltrasonicInputBack;
    ultrasonicInputLeft = RobotMap::subDriveBaseUltrasonicInputLeft;
}

void SubDriveBase::InitDefaultCommand() {
	SetDefaultCommand(new MyJoystickDrive());
}

void SubDriveBase::Periodic() {

}

void SubDriveBase::AutoDrive(double speed, double rotation) {
	differentialDrive->ArcadeDrive(speed, rotation);
}

void SubDriveBase::Stop(){
	differentialDrive->ArcadeDrive(0,0);
}

void SubDriveBase::TakeJoystickInputs(std::shared_ptr<Joystick> sticky ) {
	double throttle = (((sticky->GetRawAxis(3) + 1 ) / 4 )*-1 ) +1;
	differentialDrive->ArcadeDrive(-sticky->GetY() * throttle, sticky->GetX() * throttle);
}
