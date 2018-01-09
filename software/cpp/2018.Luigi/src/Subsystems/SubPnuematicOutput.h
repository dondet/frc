#ifndef SubPnuematicOutput_H
#define SubPnuematicOutput_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class SubPnuematicOutput : public Subsystem {
private:
	static std::shared_ptr<DoubleSolenoid> solPusher;

public:
	SubPnuematicOutput();
	void InitDefaultCommand();
	void SubPnuematicOutput::Out();
	void SubPnuematicOutput::In();
};

#endif  // SubPnuematicOutput_H
