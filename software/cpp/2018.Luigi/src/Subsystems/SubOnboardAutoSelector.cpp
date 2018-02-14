#include <Subsystems/SubOnboardAutoSelector.h>
#include <iostream>
#include "../RobotMap.h"

SubOnboardAutoSelector::SubOnboardAutoSelector() : Subsystem("OnboardAutoSelectorSubsystem") {

	swtA1 = RobotMap::subOnboardAutoSelectorSwtA1;
	swtA2 = RobotMap::subOnboardAutoSelectorSwtA2;
	swtA4 = RobotMap::subOnboardAutoSelectorSwtA4;
	swtA8 = RobotMap::subOnboardAutoSelectorSwtA8;
	swtB1 = RobotMap::subOnboardAutoSelectorSwtB1;
	swtB2 = RobotMap::subOnboardAutoSelectorSwtB2;
	swtB4 = RobotMap::subOnboardAutoSelectorSwtB4;
	swtB8 = RobotMap::subOnboardAutoSelectorSwtB8;
}

void SubOnboardAutoSelector::InitDefaultCommand() {

}

int SubOnboardAutoSelector::Read(){

	int tmpA1 = swtA1->Get() ? 0 : 1;
	int tmpA2 = swtA2->Get() ? 0 : 1;
	int tmpA4 = swtA4->Get() ? 0 : 1;
	int tmpA8 = swtA8->Get() ? 0 : 1;
	int tmpA = ( ( tmpA8 * 2 + tmpA4 ) * 2 + tmpA2 ) * 2 + tmpA1;
	std::cout << "INFO: Read Onboard Selector A: " << tmpA8 << tmpA4 << tmpA2 << tmpA1 << " (" << tmpA << ")" << std::endl;

	int tmpB1 = swtB1->Get() ? 0 : 1;
	int tmpB2 = swtB2->Get() ? 0 : 1;
	int tmpB4 = swtB4->Get() ? 0 : 1;
	int tmpB8 = swtB8->Get() ? 0 : 1;
	int tmpB = ( ( tmpB8 * 2 + tmpB4 ) * 2 + tmpB2 ) * 2 + tmpB1;
	std::cout << "INFO: Read Onboard Selector B: " << tmpB8 << tmpB4 << tmpB2 << tmpB1 << " (" << tmpB << ")" << std::endl;

	int retval = tmpA * 10 + tmpB;
	std::cout << "INFO: Read Onboard Selector return value: " << retval << std::endl;

	return retval;
}
