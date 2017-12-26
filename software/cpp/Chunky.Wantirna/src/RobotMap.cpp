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
#include "CANTalon.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Solenoid.h"
#include "ADXRs450_gyro.h"
#include "WPILib.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::subDriveBaseTnxRightMaster;
std::shared_ptr<CANTalon> RobotMap::subDriveBaseTnxLeftMaster;
std::shared_ptr<RobotDrive> RobotMap::subDriveBaseRobotDriveTwo;
std::shared_ptr<Servo> RobotMap::subGearCatcherSrvFlap1;
std::shared_ptr<Servo> RobotMap::subGearCatcherSrvFlap2;
std::shared_ptr<AnalogInput> RobotMap::subGearCatcherAngUltrasonicSensor;
std::shared_ptr<SpeedController> RobotMap::subClimberSpkClimber01;
std::shared_ptr<SpeedController> RobotMap::subClimberSpkClimber02;
std::shared_ptr<CANTalon> RobotMap::subShooterTnxShooterTop;
std::shared_ptr<CANTalon> RobotMap::subShooterTnxShooterBottom;
std::shared_ptr<CANTalon> RobotMap::subIntakeTnxIntakeRollers;
std::shared_ptr<CANTalon> RobotMap::subIntakeTnxIntakeSliders;
std::shared_ptr<DigitalInput> RobotMap::subIntakeLswSliderIn;
std::shared_ptr<DigitalInput> RobotMap::subIntakeLswSliderOut;
std::shared_ptr<SpeedController> RobotMap::subFeederVspFeederWheels;
std::shared_ptr<SpeedController> RobotMap::subFeederVspAgitatorPaddles;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<CANTalon> RobotMap::subDriveBaseTnxLeftSlave;
std::shared_ptr<CANTalon> RobotMap::subDriveBaseTnxRightSlave;
std::shared_ptr<ADXRS450_Gyro> RobotMap::subDriveBaseGyro;
std::shared_ptr<DoubleSolenoid> RobotMap::subGearCatcherPnuDoors;
std::shared_ptr<DoubleSolenoid> RobotMap::subGearCatcherPnuPusher;
std::shared_ptr<SpeedController> RobotMap::subCameraHorizontal;
std::shared_ptr<SpeedController> RobotMap::subCameraVirtical;
std::shared_ptr<Preferences> RobotMap::subCameraPrefs;

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    subDriveBaseTnxRightMaster.reset(new CANTalon(3));
    lw->AddActuator("SubDriveBase", "TnxRightMaster", subDriveBaseTnxRightMaster);
    
    subDriveBaseTnxLeftMaster.reset(new CANTalon(1));
    lw->AddActuator("SubDriveBase", "TnxLeftMaster", subDriveBaseTnxLeftMaster);
    
    subDriveBaseRobotDriveTwo.reset(new RobotDrive(subDriveBaseTnxLeftMaster, subDriveBaseTnxRightMaster));
    
    subDriveBaseRobotDriveTwo->SetSafetyEnabled(true);
        subDriveBaseRobotDriveTwo->SetExpiration(0.1);
        subDriveBaseRobotDriveTwo->SetSensitivity(0.5);
        subDriveBaseRobotDriveTwo->SetMaxOutput(1.0);

    subGearCatcherSrvFlap1.reset(new Servo(2));
    lw->AddActuator("SubGearCatcher", "SrvFlap1", subGearCatcherSrvFlap1);
    
    subGearCatcherSrvFlap2.reset(new Servo(3));
    lw->AddActuator("SubGearCatcher", "SrvFlap2", subGearCatcherSrvFlap2);
    
    subGearCatcherAngUltrasonicSensor.reset(new AnalogInput(1));
    lw->AddSensor("SubGearCatcher", "AngUltrasonicSensor", subGearCatcherAngUltrasonicSensor);
    
    //Commented out so that the camera can run on these motors
    //subClimberSpkClimber01.reset(new Spark(4));
    //lw->AddActuator("SubClimber", "SpkClimber01", std::static_pointer_cast<Spark>(subClimberSpkClimber01));

    //subClimberSpkClimber02.reset(new Spark(5));
    //lw->AddActuator("SubClimber", "SpkClimber02", std::static_pointer_cast<Spark>(subClimberSpkClimber02));
    
    subShooterTnxShooterTop.reset(new CANTalon(5));
    lw->AddActuator("SubShooter", "TnxShooterTop", subShooterTnxShooterTop);
    
    subShooterTnxShooterBottom.reset(new CANTalon(6));
    lw->AddActuator("SubShooter", "TnxShooterBottom", subShooterTnxShooterBottom);
    
    subIntakeTnxIntakeRollers.reset(new CANTalon(7));
    lw->AddActuator("SubIntake", "TnxIntakeRollers", subIntakeTnxIntakeRollers);
    
    subIntakeTnxIntakeSliders.reset(new CANTalon(8));
    lw->AddActuator("SubIntake", "TnxIntakeSliders", subIntakeTnxIntakeSliders);
    
    subIntakeLswSliderIn.reset(new DigitalInput(0));
    lw->AddSensor("SubIntake", "LswSliderIn", subIntakeLswSliderIn);
    
    subIntakeLswSliderOut.reset(new DigitalInput(1));
    lw->AddSensor("SubIntake", "LswSliderOut", subIntakeLswSliderOut);
    
    subFeederVspFeederWheels.reset(new VictorSP(1));
    lw->AddActuator("SubFeeder", "VspFeederWheels", std::static_pointer_cast<VictorSP>(subFeederVspFeederWheels));
    
    subFeederVspAgitatorPaddles.reset(new VictorSP(0));
    lw->AddActuator("SubFeeder", "VspAgitatorPaddles", std::static_pointer_cast<VictorSP>(subFeederVspAgitatorPaddles));
    
    //Camera Motors - Not in RobotBuilder
    subCameraHorizontal.reset(new Spark(6));
    lw->AddActuator("SubCamera", "SpkCameraHorizontal", std::static_pointer_cast<Spark>(subCameraHorizontal));
    subCameraVirtical.reset(new Spark(4));
    lw->AddActuator("SubCamera", "SpkCameraVirtical", std::static_pointer_cast<Spark>(subCameraVirtical));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    // Setup encoders on master drive motors for position control
    //
    subDriveBaseTnxLeftMaster->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    subDriveBaseTnxRightMaster->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    subDriveBaseTnxLeftMaster->SetSensorDirection(true);
    subDriveBaseTnxRightMaster->SetSensorDirection(true);
//    subDriveBaseTnxLeftMaster->SetPosition(0);
//    subDriveBaseTnxRightMaster->SetPosition(0);

    // Make Rear drive motors followers and configure FPID profile slot
    //
    subDriveBaseTnxLeftSlave.reset(new CANTalon(2));
    lw->AddActuator("SubDriveBase", "TnxLeftSlave", subDriveBaseTnxLeftSlave);
    subDriveBaseTnxRightSlave.reset(new CANTalon(4));
    lw->AddActuator("SubDriveBase", "TnxRightSlave", subDriveBaseTnxRightSlave);

    double LeftFgain = 0.185683;    double RightFgain = 0.186462;
    //double LeftPgain = 1.2000;    double RightPgain = 1.2000;
    double LeftPgain = 1.0000;      double RightPgain = 1.0000;
    double LeftIgain = 0.0;         double RightIgain = 0.0;
    double LeftDgain = 0.0;         double RightDgain = 0.0;

    subDriveBaseTnxLeftMaster->SelectProfileSlot(1);
    subDriveBaseTnxLeftMaster->SetF(LeftFgain);
    subDriveBaseTnxLeftMaster->SetP(LeftPgain);
    subDriveBaseTnxLeftMaster->SetI(LeftIgain);
    subDriveBaseTnxLeftMaster->SetD(LeftDgain);
    subDriveBaseTnxLeftSlave->SetControlMode(CANSpeedController::kFollower);
    subDriveBaseTnxLeftSlave->Set(1);
    subDriveBaseTnxRightMaster->SelectProfileSlot(1);
    subDriveBaseTnxRightMaster->SetF(RightFgain);
    subDriveBaseTnxRightMaster->SetP(RightPgain);
    subDriveBaseTnxRightMaster->SetI(RightIgain);
    subDriveBaseTnxRightMaster->SetD(RightDgain);
    subDriveBaseTnxRightSlave->SetControlMode(CANSpeedController::kFollower);
    subDriveBaseTnxRightSlave->Set(3);

    // Setup encoders on shooter motors for speed control
    //
    // (NOTE: these encoders are the same as the CTRE Mag Encoder (see
    // https://content.vexrobotics.com/vexpro/pdf/217-5046-Instructions-20160126.PDF
    // and section 7 of
    // https://content.vexrobotics.com/vexpro/pdf/Magnetic-Encoder-User's-Guide-01282016.pdf)
    //
    subShooterTnxShooterTop->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    subShooterTnxShooterTop->SetSensorDirection(false);
    subShooterTnxShooterTop->ConfigNominalOutputVoltage(+0.0f, -0.0f);
    subShooterTnxShooterTop->ConfigPeakOutputVoltage(+12.0f, -12.0f);
    subShooterTnxShooterTop->SelectProfileSlot(0);
    subShooterTnxShooterTop->SetF(0.02525);
    subShooterTnxShooterTop->SetP(0.02);
    subShooterTnxShooterTop->SetI(0.0);
    subShooterTnxShooterTop->SetD(0.0);
    //subShooterTnxShooterTop->SetControlMode(CANSpeedController::kSpeed); << this command is now in the subsystem Run() class
    //subShooterTnxShooterTop->SetControlMode(CANSpeedController::kPercentVbus); << this command is now in the subsystem Stop() class

    subShooterTnxShooterBottom->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    subShooterTnxShooterBottom->SetSensorDirection(false);
    subShooterTnxShooterBottom->ConfigNominalOutputVoltage(+0.0f, -0.0f);
    subShooterTnxShooterBottom->ConfigPeakOutputVoltage(+12.0f, -12.0f);
    subShooterTnxShooterBottom->SelectProfileSlot(0);
    subShooterTnxShooterBottom->SetF(0.02525);
    subShooterTnxShooterBottom->SetP(0.02);
    subShooterTnxShooterBottom->SetI(0.0);
    subShooterTnxShooterBottom->SetD(0.0);
    //subShooterTnxShooterBottom->SetControlMode(CANSpeedController::kSpeed); << this command is now in the subsystem Run() class
    //subShooterTnxShooterBottom->SetControlMode(CANSpeedController::kPercentVbus); << this command is now in the subsystem Stop() class

    //Create and calibrate gyroscope
    //
//    subDriveBaseGyro.reset(new ADXRS450_Gyro);
//    lw->AddSensor("SubDriveBase", "Gyro", subDriveBaseGyro);
//    subDriveBaseGyro->Calibrate();

    //Create pnuematics solenoids
    subGearCatcherPnuPusher.reset(new DoubleSolenoid(0,2));
    lw->AddSensor("SubGearCatcher", "PnuPusher", subGearCatcherPnuPusher);
    subGearCatcherPnuDoors.reset(new DoubleSolenoid(1,3));
    lw->AddSensor("SubGearCatcher", "PnuDoors", subGearCatcherPnuDoors);

}
