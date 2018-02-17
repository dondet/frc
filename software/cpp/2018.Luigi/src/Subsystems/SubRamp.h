#ifndef SubRamp_H
#define SubRamp_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <SmartDashboard/SmartDashboard.h>

class SubRamp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<VictorSP> SPLeft;
	int _timerCase = 0;
	int _timerValue = 0;

public:
	SubRamp();
	void InitDefaultCommand();
	void DropRamp();
	void StopRamp();
	void ResetRamp();
	void Periodic();
};

#endif  // SubRamp_H
