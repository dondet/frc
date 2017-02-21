// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef CMDAUTOTURN_H
#define CMDAUTOTURN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class CmdAutoTurn: public Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	CmdAutoTurn(int mode, double Power, double Angle);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
    double startangle;
    double sensorcorrection;
    double correctedangle;
    double gyro;
    double anglenow;
    double delta;
    double powerdownthreshold = 5;
    double allowederror = 0.5;
    double power;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES

    int m_Mode;
    double m_Power;
    double m_Angle;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=VARIABLES
    double p_constant;
    double i_constant;
    double d_constant;
    double currentAngle;
    int timeToCorrect;

    PIDController* TurnController;
};

#endif
