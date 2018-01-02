// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
// #include "Custom/MotionProfileExample.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Commands/CmdAutonomous.h"
#include "Subsystems/SubClimber.h"
#include "Subsystems/SubDriveBase.h"
#include "Subsystems/SubFeeder.h"
#include "Subsystems/SubGearCatcher.h"
#include "Subsystems/SubIntake.h"
#include "Subsystems/SubShooter.h"
#include "Subsystems/SubCamera.h"
#include "OI.h"

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

    static std::shared_ptr<SubDriveBase> subDriveBase;
    static std::shared_ptr<SubGearCatcher> subGearCatcher;
    static std::shared_ptr<SubClimber> subClimber;
    static std::shared_ptr<SubShooter> subShooter;
    static std::shared_ptr<SubIntake> subIntake;
    static std::shared_ptr<SubFeeder> subFeeder;
    static std::shared_ptr<SubCamera> subCamera;

    //Preferences *icPrefs;
    //double icPrefCameraP;
    //double icPrefCameraI;
    //double icPrefCameraD;

    virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
//	virtual double* GetPreferences();


private:
	frc::SendableChooser<frc::Command*> chooser;
	// already declared above - - - std::unique_ptr<frc::Command> autonomousCommand;

};
#endif
