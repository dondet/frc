#include "SubDriveBase.h"
#include "Commands/MyJoystickDrive.h"


SubDriveBase::SubDriveBase() : frc::Subsystem("SubDriveBase") {
	sRXleft = RobotMap::subDriveBaseSRXleft;
    sRXright = RobotMap::subDriveBaseSRXright;
    differentialDrive = RobotMap::subDriveBaseDifferentialDrive;


    //ultrasonicInputFront = RobotMap::subDriveBaseUltrasonicInputFront;
    //ultrasonicInputRight = RobotMap::subDriveBaseUltrasonicInputRight;
    //ultrasonicInputBack = RobotMap::subDriveBaseUltrasonicInputBack;
    //ultrasonicInputLeft = sRobotMap::subDriveBaseUltrasonicInputLeft;

    i2c = RobotMap::i2c;

   // i2c = new I2C(I2C::Port::kOnboard, 8);

}

void SubDriveBase::InitDefaultCommand() {
	SetDefaultCommand(new MyJoystickDrive());
}

void SubDriveBase::Periodic() {

	//if (++_Ultraloops >= 30) {

	//frontUValue = ((((ultrasonicInputFront->GetValue())/ (5.0 / 500.0))/1000.0)+5.0);
	//rightUValue = ((((ultrasonicInputRight->GetValue())/ (5.0 / 500.0))/1000.0)+5.0);
	//backUValue = ((((ultrasonicInputBack->GetValue())/ (5.0 / 500.0))/1000.0)+5.0);
	//leftUValue = ((((ultrasonicInputLeft->GetValue())/ (5.0 / 500.0))/1000.0)+5.0);
	//frontUValue = ((ultrasonicInputFront->GetValue())/ 100000.0 );
	//frontUValue = ultrasonicInputFront->GetValue();

	//code for DIO echo ultrasonic sensors
	//ultrasonicInputFront->SetAutomaticMode(true);
	//ultrasonicInputRight->SetAutomaticMode(true);
	//ultrasonicInputBack->SetAutomaticMode(true);
	//ultrasonicInputFront->SetAutomaticMode(true);
	//frontUValue = ultrasonicInputFront->GetRangeInches();
	//rightUValue = ultrasonicInputRight->GetRangeInches();
	//backUValue = ultrasonicInputBack->GetRangeInches();
	//leftUValue = ultrasonicInputLeft->GetRangeInches();

	//frc::SmartDashboard::PutNumber("Ultra, front", frontUValue);
	//frc::SmartDashboard::PutNumber("Ultra, right", rightUValue);
	//frc::SmartDashboard::PutNumber("Ultra, back", backUValue);
	//frc::SmartDashboard::PutNumber("Ultra, left", leftUValue);
	//frc::SmartDashboard::PutNumber("Ultra RAW, DIO:0", ultrasonicInputFront->GetValue());
    uint8_t fred[255];
    uint8_t joe[255];
    std::string blah(fred, fred + sizeof(fred));
    i2c->Transaction(joe, 0, fred, 6);
	  frc::SmartDashboard::PutString("i2c Reading", blah);

	//_Ultraloops = 0;

//	}

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
