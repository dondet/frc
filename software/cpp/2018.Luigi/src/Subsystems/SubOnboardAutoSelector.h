#ifndef SubOnboardAutoSelector_H
#define SubOnboardAutoSelector_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix.h>
#include <WPILib.h>

class SubOnboardAutoSelector : public Subsystem {
private:

	std::shared_ptr<DigitalInput> swtA1;
	std::shared_ptr<DigitalInput> swtA2;
	std::shared_ptr<DigitalInput> swtA4;
	std::shared_ptr<DigitalInput> swtA8;
	std::shared_ptr<DigitalInput> swtB1;
	std::shared_ptr<DigitalInput> swtB2;
	std::shared_ptr<DigitalInput> swtB4;
	std::shared_ptr<DigitalInput> swtB8;

public:
	SubOnboardAutoSelector();
	void InitDefaultCommand();
	int Read();

};

#endif  // SubOnboardAutoSelector_H
