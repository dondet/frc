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
std::shared_ptr<WPI_TalonSRX> RobotMap::driveBasetnxRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::driveBasetnxLeft;
std::shared_ptr<frc::DifferentialDrive> RobotMap::driveBaseDifferentialDrive1;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    //frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
    driveBasetnxRight.reset(new WPI_TalonSRX(0));
    
    driveBasetnxLeft.reset(new WPI_TalonSRX(1));
    
    driveBaseDifferentialDrive1.reset(new frc::DifferentialDrive(*driveBasetnxLeft, *driveBasetnxRight));
    //lw->AddActuator("DriveBase", "Differential Drive 1", driveBaseDifferentialDrive1);
    driveBaseDifferentialDrive1->SetSafetyEnabled(true);
        driveBaseDifferentialDrive1->SetExpiration(0.1);
        driveBaseDifferentialDrive1->SetMaxOutput(1.0);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
