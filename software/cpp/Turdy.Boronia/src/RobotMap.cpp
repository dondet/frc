// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::subDriveBaseSRXleft;
std::shared_ptr<WPI_TalonSRX> RobotMap::subDriveBaseSRXright;
std::shared_ptr<frc::DifferentialDrive> RobotMap::subDriveBaseMyFirstDifferentialDrive;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::subDriveBaseSRXleftSlave;
std::shared_ptr<WPI_TalonSRX> RobotMap::subDriveBaseSRXrightSlave;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
//    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    subDriveBaseSRXleft.reset(new WPI_TalonSRX(1));
    
    
    subDriveBaseSRXright.reset(new WPI_TalonSRX(3));
    
    
    subDriveBaseMyFirstDifferentialDrive.reset(new frc::DifferentialDrive(*subDriveBaseSRXleft, *subDriveBaseSRXright));
//    lw->AddActuator("SubDriveBase", "MyFirstDifferential Drive", subDriveBaseMyFirstDifferentialDrive);
    subDriveBaseMyFirstDifferentialDrive->SetSafetyEnabled(false);
        subDriveBaseMyFirstDifferentialDrive->SetExpiration(0.1);
        subDriveBaseMyFirstDifferentialDrive->SetMaxOutput(1.0);



    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

        subDriveBaseSRXleftSlave.reset(new WPI_TalonSRX(2));
        subDriveBaseSRXleftSlave->Set( ctre::phoenix::motorcontrol::ControlMode::Follower, 1);

        subDriveBaseSRXrightSlave.reset(new WPI_TalonSRX(4));
        subDriveBaseSRXrightSlave->Set( ctre::phoenix::motorcontrol::ControlMode::Follower, 3);
}