

#include "SubEncodedArm.h"
#include "../RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include "../Commands/CmdArmDefault.h"
#include "../Commands/CmdKeepArmStill.h"

SubEncodedArm::SubEncodedArm() : Subsystem("ExampleSubsystem") {

	_talon = RobotMap::subEncodedArmTnx;
	_potMain = RobotMap::subEncodedArmPot;

}

void SubEncodedArm::Periodic() {

	lc++;
	if( lc > 10){
		SmartDashboard::PutNumber("POT Value", _potMain->GetValue());
		SmartDashboard::PutNumber("POT Voltage", _potMain->GetVoltage());
		SmartDashboard::PutNumber("POT Value Average", _potMain->GetAverageValue());
		SmartDashboard::PutNumber("POT Voltage Average", _potMain->GetAverageVoltage());
		lc = 0;
	}
}

void SubEncodedArm::InitDefaultCommand() {
	SetDefaultCommand(new CmdKeepArmStill());

}

void SubEncodedArm::ArmJoyMove(std::shared_ptr<frc::Joystick> controller) {
	_axis5 = controller->GetRawAxis(5); //up down control axis
	double speed = 0.0;
	speed = _axis5/4;
	_talon->Set(speed);  //Probably will need some extra stuff in here for better control / movement

}

void SubEncodedArm::Stop() {	//Used by the default command
	_talon->Set(0.0);
}


void SubEncodedArm::VoltageControl(double percentage) {
  _talon->Set(percentage);
}

double SubEncodedArm::GetArmAngle() {
  double value = _potMain->GetAverageValue();
  value = value - 332; //number of sensor units when arm is flat back
  value = value / 2040; //range of sensor units from back to front
  value = value * 180; //range of angles in degrees
  value = value - 90; //half of total range of angles in degrees

  return value;
}
