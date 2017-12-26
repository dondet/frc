// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include "WPILib.h"
#include "Custom/Instrumentation.h"
#include "Custom/MotionProfileExample.h"
#include "CANTalon.h"
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/SmartDashboard.h"
#include <CameraServer.h>
#include "Commands/CmdAuto2ShootGoals.h"
#include "Commands/CmdAuto3DeployGearFromRight.h"
#include "Commands/CmdAuto4DeployGearFromLeft.h"
#include "Commands/CmdAuto5MotionProfileToLeftPeg.h"
#include "Commands/CmdAuto6MotionProfileToRightPeg.h"
#include "Commands/CmdAuto7MotionProfileToMidPeg.h"
#include "Commands/CmdAuto8MotionProfileToBaseline.h"
#include "Commands/CmdAuto9DoNothing.h"
#include "Commands/CmdCameraTrack.h"

std::shared_ptr<SubCamera> Robot::subCamera;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<SubDriveBase> Robot::subDriveBase;
std::shared_ptr<SubGearCatcher> Robot::subGearCatcher;
std::shared_ptr<SubClimber> Robot::subClimber;
std::shared_ptr<SubShooter> Robot::subShooter;
std::shared_ptr<SubIntake> Robot::subIntake;
std::shared_ptr<SubFeeder> Robot::subFeeder;
std::unique_ptr<OI> Robot::oi;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION



void Robot::RobotInit() {

    RobotMap::init();

    // Setup camera ...
    // CameraServer::GetInstance()->StartAutomaticCapture();
    cs::UsbCamera cameraA = CameraServer::GetInstance()->StartAutomaticCapture();
    cs::UsbCamera cameraB = CameraServer::GetInstance()->StartAutomaticCapture();
    // NOTE: 640x480 => observed as 4mbps at 7/8fps in smart dashboard
    // NOTE: 320x240 => observed as 3mbps at 15/16fps in smart dashboard
    // set resolution to 320, 240 and FPS to 10 gives each camera stream <2Mbps so
    // we should be able to handle a couple of cameras without flooding the network
    cameraA.SetResolution(320, 240);
    cameraA.SetFPS(10);
    // cameraA.SetExposureManual(5);
    cameraB.SetResolution(320, 240);
    cameraB.SetFPS(10);
    //cameraB.SetExposureManual(5);

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    subDriveBase.reset(new SubDriveBase());
    subGearCatcher.reset(new SubGearCatcher());
    subClimber.reset(new SubClimber());
    subShooter.reset(new SubShooter());
    subIntake.reset(new SubIntake());
    subFeeder.reset(new SubFeeder());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    subCamera.reset(new SubCamera());

    // This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new CmdAutonomous());

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//Create autonomous selector
	chooser.AddObject("Auto 1: Deploy Gear", new CmdAutonomous());
	chooser.AddObject("Auto 2: Shoot Goals", new CmdAuto2ShootGoals());
	chooser.AddObject("Auto 3: Deploy Gear From Right", new CmdAuto3DeployGearFromRight());
	chooser.AddObject("Auto 4: Deploy Gear From Left", new CmdAuto4DeployGearFromLeft());
	chooser.AddObject("Auto 5: Left Peg", new CmdAuto5MotionProfileToLeftPeg());
	chooser.AddObject("Auto 6: Right Peg", new CmdAuto6MotionProfileToRightPeg());
	chooser.AddDefault("Auto 7: Middle Peg", new CmdAuto7MotionProfileToMidPeg());
	chooser.AddObject("Auto 8: BaseLine", new CmdAuto8MotionProfileToBaseline());
	chooser.AddObject("Auto 9: Do Nothing", new CmdAuto9DoNothing());
	frc::SmartDashboard::PutData("Autonomous modes", &chooser);

	// Setup preferences
	icPrefs = Preferences::GetInstance();
	icPrefCameraP = icPrefs->GetDouble("P", 0.0);
	icPrefCameraI = icPrefs->GetDouble("I", 0.0);
	icPrefCameraD = icPrefs->GetDouble("D", 0.0);


	// inject preferences into subsystems
	subCamera->SetPID( icPrefCameraP, icPrefCameraI, icPrefCameraD );

}

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
    // turn off the safety as we know auo code is managing motor control and
	// Robot Drive will be bleating if we do not attend to it often enough...
	RobotMap::subDriveBaseRobotDriveTwo->SetExpiration(60);
	autonomousCommand.reset(chooser.GetSelected());
	if (autonomousCommand.get() != nullptr) {
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	// reset the safety for teleop mode as we are not using direct motor control from now on ...
    RobotMap::subDriveBaseRobotDriveTwo->SetExpiration(0.2);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

/*
*double* Robot::GetPreferences() {
	double m_prefs[] = {prefs->GetDouble("p"),
			prefs->GetDouble("i"),
			prefs->GetDouble("d")};
	return m_prefs;
}
*/

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

