

#include "PIDPot.h"
#include "../RobotMap.h"
#include "../Robot.h"

PIDPot::PIDPot() {
	// TODO Auto-generated constructor stub
	_potMain = RobotMap::subEncodedArmPot;

}

double PIDPot::PIDGet() {

	double target =	Robot::subEncodedArm->PIDGetSetPoint();

	int potAvg = _potMain->GetAverageValue();

	double error = abs(potAvg - target);

	double newTarget = error * potAvg;

	return newTarget;

	//return _potMain->GetAverageValue();

}

PIDPot::~PIDPot() {
	// TODO Auto-generated destructor stub
}

