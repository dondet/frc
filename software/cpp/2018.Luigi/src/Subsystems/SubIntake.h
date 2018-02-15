#ifndef SubIntake_H
#define SubIntake_H

#include <Commands/Subsystem.h>
#include <ctre/phoenix.h>
#include <WPILib.h>

class SubIntake : public Subsystem {
private:
	std::shared_ptr<WPI_TalonSRX> tnxRight;
	std::shared_ptr<WPI_TalonSRX> tnxLeft;
	std::shared_ptr<VictorSP> spFinger;

	std::shared_ptr<DigitalInput> swtFingerUpLimit;
	std::shared_ptr<DigitalInput> swtLeftLimit;
	std::shared_ptr<DigitalInput> swtRightLimit;

public:
	SubIntake();
	void InitDefaultCommand();
	void In(double speed);
	void Out(double speed);
	void Stop();
	bool GetSwitches();
	void FingerDown();
	void FingerUp();
	void FingerStop();
};

#endif  // SubIntake_H
