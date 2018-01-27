//#include "SubArmLift.h"
//#include "../RobotMap.h"
//#include "Commands/CmdArmStop.h"
//
//SubArmLift::SubArmLift() : Subsystem("ExampleSubsystem") {
//	tnxLeft = RobotMap::subArmLiftLeft;
//	tnxRight = RobotMap::subArmLiftRight;
//
//	swtTopLimit = RobotMap::subArmLiftTopLimit;
//	swtBottomLimit = RobotMap::subArmLiftBottomLimit;
//}
//
//void SubArmLift::InitDefaultCommand() {
//	SetDefaultCommand(new CmdArmStop());
//}
//
//void SubArmLift::Up(){
//	tnxRight->Set(-1);
//	tnxLeft->Set(1);
//}
//
//void SubArmLift::Down(){
//	tnxRight->Set(1);
//	tnxLeft->Set(-1);
//}
//
//void SubArmLift::Stop(){
//	tnxLeft->Set(0);
//	tnxRight->Set(0);
//}
//
//bool SubArmLift::GetTopSwitch(){
//	return swtTopLimit->Get();
//}
//
//bool SubArmLift::GetBottomSwitch(){
//	return swtBottomLimit->Get();
//}
//// Put methods for controlling this subsystem
//// here. Call these from Commands.
