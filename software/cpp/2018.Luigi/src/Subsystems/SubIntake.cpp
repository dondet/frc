#include "SubIntake.h"
#include "../RobotMap.h"
#include "Commands/CmdIntakeDefault.h"

SubIntake::SubIntake() : Subsystem("ExampleSubsystem") {
	tnxRight = RobotMap::subIntakeTnxRight;
	tnxLeft = RobotMap::subIntakeTnxLeft;
	spFinger = RobotMap::subIntakeSpFinger;

	swtFingerUpLimit = RobotMap::subIntakeSwtFingerUpLimit;
	swtLeftLimit = RobotMap::subIntakeSwtLeftLimit;
	swtRightLimit = RobotMap::subIntakeSwtRightLimit;

	//FingerUp();  //idk if we will need this
}

void SubIntake::InitDefaultCommand() {
	SetDefaultCommand(new CmdIntakeDefault());
}

void SubIntake::Out(double speed){
	tnxRight->Set(speed);
	tnxLeft->Set(-speed);
}

void SubIntake::In(double speed){
	tnxRight->Set(-speed);
	tnxLeft->Set(speed);
}

void SubIntake::Stop(){
	tnxRight->Set(0);
	tnxLeft->Set(0);
}

void SubIntake::FingerDown() {
	spFinger->Set(-0.4);
}

void SubIntake::FingerUp() {
	if (swtFingerUpLimit->Get()) {
		spFinger->Set(0.0);
	} else {
		spFinger->Set(0.1);
	}
}

void SubIntake::FingerStop() {
	spFinger->Set(0.0);
}

bool SubIntake::GetSwitches(){
	//True if both buttons are pressed
	if (not swtLeftLimit->Get() & not swtRightLimit->Get() ){	//Added nots because switches are normally closed
		return true;
	} else {
		return false;
	}
}
