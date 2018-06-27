#include "MotionProfileControl.h"
#include "Instrumentation.h"
#include <iostream>

// constructor for single channel MP ...

MotionProfileControl::MotionProfileControl(	std::shared_ptr<TalonSRX> TalonA,
											std::string profile,
											std::string suffixA,
											int profileTimeout)
: _mpData(suffixA), _notifier(&MotionProfileControl::PeriodicTask, this), _profileTimeout(profileTimeout)
{

	//Assign variables
	_channels = 1;
	_talonA = TalonA;
	_profile = profile;
	_state = 0;
	_bStart = false;
	_loopTimeout = -1;
	_setValue = SetValueMotionProfile::Disable;
	_notifier.StartPeriodic(0.005);
	_loopCount = 0;
	_pointsprocessed = 0;

	_talonA->ChangeMotionControlFramePeriod(5);

	isRunning = true;
}

// constructor for two channel MP ...

MotionProfileControl::MotionProfileControl(	std::shared_ptr<TalonSRX> TalonA,
											std::shared_ptr<TalonSRX> TalonB,
											std::string profile,
											std::string suffixA,
											std::string suffixB,
											int profileTimeout)
:  _mpData(suffixA, suffixB), _notifier(&MotionProfileControl::PeriodicTask, this), _profileTimeout(profileTimeout)
{

	//Assign variables
	_channels = 2;
	_talonA = TalonA;
	_talonB = TalonB;
	_profile = profile;
	_state = 0;
	_bStart = false;
	_loopTimeout = -1;
	_setValue = SetValueMotionProfile::Disable;
	_notifier.StartPeriodic(0.005);
	_loopCount = 0;
	_pointsprocessed = 0;

	_talonA->ChangeMotionControlFramePeriod(5);
	_talonB->ChangeMotionControlFramePeriod(5);

	isRunning = true;
}

void MotionProfileControl::PeriodicTask(){
	//Make sure we are in Motion Profile mode
	bool modeIsMP;
	switch( _channels ) {
		case( 1 ) :
			if( _talonA->GetControlMode() == ControlMode::MotionProfile ) {
				modeIsMP = true;
			}else {
				modeIsMP = false;
			}
			break;
		case( 2 ) :
			if( (_talonA->GetControlMode() == ControlMode::MotionProfile) && (_talonB->GetControlMode() == ControlMode::MotionProfile ) ) {
				modeIsMP = true;
			} else {
				modeIsMP = false;
			}
			break;
	default :
		modeIsMP = false;
		std::cout << "MotionProfileControl: periodic task: unsupported channels" << std::endl;
	}
	if( modeIsMP ) {
		//Move points from top buffer (on RIO) to bottom buffer (on Talon)
		if( _channels > 0 ) { _talonA->ProcessMotionProfileBuffer(); }
		if( _channels > 1 ) { _talonB->ProcessMotionProfileBuffer(); }
	}

	// we need to check that profile is actually running, and only process timeout counter once we have kicked off the profile
	if(_state > 0) {
//		std::cout << "MotionProfileControl: periodic task: MP has commenced - time out timer kicked off" << std::endl;
		execounter++;
		if ((execounter >= 200) and (_profileTimeout > -1)) {
			_profileTimeout--;
			execounter = 0;
		}

	} else {
//		std::cout << "MotionProfileControl: periodic task: MP has not commenced yet - time out timer on hold" << std::endl;
	}
}

void MotionProfileControl::reset(){

	std::cout << "MotionProfileControl: reset" << std::endl;

	//clean buffer
	if( _channels > 0 ) { _talonA->ClearMotionProfileTrajectories(); }
	if( _channels > 1 ) { _talonB->ClearMotionProfileTrajectories(); }

	//disable talon, and reset state
	_setValue = SetValueMotionProfile::Disable;
	_state = 0;
	_loopTimeout = -1;
	_bStart = false;
	execounter = 0;

	//Reset Sensor positions to zero for future profiles
	if( _channels > 0 ) { _talonA->SetSelectedSensorPosition(0, 0, 10); }
	if( _channels > 1 ) { _talonB->SetSelectedSensorPosition(0, 0, 10); }
}

void MotionProfileControl::control(){

	//track time to make sure things don't get stuck
	if (_loopTimeout < 0) {
		//do nothing, timeout is disabled
	} else {
		if (_loopTimeout == 0) {
			//Error condition, no progress
			Instrumentation::OnNoProgress();
		} else {
			//Decrement timeout
			--_loopTimeout;
		}
	}

	switch (_state) {

		case 0: //Start filling top-buffer with points
			if (_bStart) {
				_bStart = false;
				_setValue = SetValueMotionProfile::Disable;
				// try sending some points ...
				streamToTopBuffer( true );
				_state = 1;
				_loopTimeout = kNumLoopsTimeout;
			}
			break;

		case 1: //Start driving
			bool minPoints;
			switch( _channels ) {
				case( 1 ) :
					if ( _statusA.btmBufferCnt > kMinPointsInTalon ) {
						minPoints = true;
					} else {
						minPoints = false;
					}
					break;
				case( 2 ) :
					if ( (_statusA.btmBufferCnt > kMinPointsInTalon) && (_statusB.btmBufferCnt > kMinPointsInTalon) ) {
						minPoints = true;
					} else {
						minPoints = false;
					}
					break;
				default :
					std::cout << "MotionProfileControl: control: unsupported channels" << std::endl;
					minPoints = false;
			}
			if( minPoints ) {
				_setValue = SetValueMotionProfile::Enable;
				// try sending some points ...
				streamToTopBuffer( false );
				_state = 2;
				_loopTimeout = kNumLoopsTimeout;
			}
			break;

		case 2: //Continue or stop driving
			bool isUnderrun;
			switch( _channels ) {
				case( 1 ) :
					if ( _statusA.isUnderrun == false ) {
						isUnderrun = false;
					} else {
						isUnderrun = true;
					}
					break;
				case( 2 ) :
					if ( (_statusA.isUnderrun == false) && (_statusB.isUnderrun == false) ) {
						isUnderrun = false;
					} else {
						isUnderrun = true;
					}
					break;
				default :
					std::cout << "MotionProfileControl: control: unsupported channels" << std::endl;
					isUnderrun = true;
			}
			if( isUnderrun ) {
				//Talons don't have enough points, log an underrun
			} else {
				//things going well, reset timeout
				_loopTimeout = kNumLoopsTimeout;
			}

			// try sending some points ...
			streamToTopBuffer( false );

			//Stop if profile timed out
			if (_profileTimeout <= 0) {
				std::cout << "Profile timed out" << std::endl;
				stop();
			}

			//Uncomment these to find out why the MP isn't ending
//			if( _channels > 0 ) {
//				std::cout << "_statusA.activePointValid: " << _statusA.activePointValid << std::endl;
//				std::cout << "_statusA.isLast: " << _statusA.isLast << std::endl;
//			}
//			if( _channels > 1 ) {
//				std::cout << "_statusB.activePointValid: " << _statusB.activePointValid << std::endl;
//				std::cout << "_statusB.isLast: " << _statusB.isLast << std::endl;
//			}

			// Check for last trajectory point (i.e. finished motion profile) if so then hold
			bool holdit;
			switch( _channels ) {
				case( 1 ) :
					if ( _statusA.activePointValid && _statusA.isLast ){
						holdit = true;
					} else {
						holdit = false;
					}
					break;
				case( 2 ) :
					if ( (_statusA.activePointValid && _statusA.isLast) || (_statusB.activePointValid && _statusB.isLast) ){
						holdit = true;
					} else {
						holdit = false;
					}
					break;
				default :
					std::cout << "MotionProfileControl: control: unsupported channels" << std::endl;
					holdit = false;
			}
			if( holdit ) {
				_setValue = SetValueMotionProfile::Hold;
				stop();
			}
			break;
		}
	if( _channels > 0 ) {
		// Get the motion profile status every loop ...
		_talonA->GetMotionProfileStatus(_statusA);
		// Update heading, position and velocity every loop ...
		_headingA = _talonA->GetActiveTrajectoryHeading();
		_posA = _talonA->GetActiveTrajectoryPosition();
		_velA = _talonA->GetActiveTrajectoryVelocity();
//		Instrumentation::Process(_statusA, _posA, _velA, _headingA);;
	}
	if( _channels > 1 ) {
		// Get the motion profile status every loop ...
		_talonB->GetMotionProfileStatus(_statusB);
		// Update heading, position and velocity every loop ...
		_headingB = _talonB->GetActiveTrajectoryHeading();
		_posB = _talonB->GetActiveTrajectoryPosition();
		_velB = _talonB->GetActiveTrajectoryVelocity();
		// printfs and/or logging ... we really need to process statuses in a better
		// way for channels>1 as they will appear jumbled in the console when we do it like this
//		Instrumentation::Process(_statusB, _posB, _velB, _headingB);
	}

}

void MotionProfileControl::streamToTopBuffer( bool firstpass ){

	if( firstpass ) {

		//Clear the buffer of previous Motion Profiles
		if( _channels > 0 ) { _talonA->ClearMotionProfileTrajectories(); }
		if( _channels > 1 ) { _talonB->ClearMotionProfileTrajectories(); }

		//set the base trajectory period to zero, use the individual trajectory periods in PushToTalon(...)
		if( _channels > 0 ) { _talonA->ConfigMotionProfileTrajectoryPeriod(0, 10); }
		if( _channels > 1 ) { _talonB->ConfigMotionProfileTrajectoryPeriod(0, 10); }
	}

	//Check if talons have run out of points
	if( _channels > 0 ) {
		if( _statusA.hasUnderrun){
			// Log it in the console
			Instrumentation::OnUnderrun();
			/*
			 * Clear the error. This is what seperates "has underrun" from
			 * "is underrun", because the former is cleared by the application.
			 * That way, we never miss logging it.
			 */
			_talonA->ClearMotionProfileHasUnderrun(10);
		}
	}
	if( _channels > 1 ) {
		if(_statusB.hasUnderrun ){
			// Log it in the console
			Instrumentation::OnUnderrun();
			/*
			 * Clear the error. This is what seperates "has underrun" from
			 * "is underrun", because the former is cleared by the application.
			 * That way, we never miss logging it.
			 */
			_talonB->ClearMotionProfileHasUnderrun(10);
		}
	}

	// decide how many blocks to process
	int _minTopBufferRem;
	int _topBufferRemA;
	int _topBufferRemB;
	switch( _channels ) {
		case( 1 ) :
			_topBufferRemA = _statusA.topBufferRem;
			_minTopBufferRem = _topBufferRemA;
			break;
		case( 2 ) :
			_topBufferRemA = _statusA.topBufferRem;
			_topBufferRemB = _statusB.topBufferRem;
			_minTopBufferRem = ( _topBufferRemA < _topBufferRemB ) ? _topBufferRemA : _topBufferRemB;
			break;
		default :
			std::cout << "MotionProfileControl: stream to to buffer: unsupported channels" << std::endl;
	}


	int _blocks = 0;
	if( firstpass ) {
		// process as many blocks as possible (zero or more)
		_blocks = trunc( _minTopBufferRem / kBlockSize );
	}
	if( ! firstpass ) {
		// process zero or one blocks
		_blocks = ( _minTopBufferRem > kBlockSize ) ? 1 : 0;
	}

//	std::cout << "INFO: processing " << _blocks << " blocks" << std::endl;

	// no process the zero or more blocks
	while( _blocks > 0 ) {
		int mpsize = _mpData.GetNumberOfPoints();
		int start = _pointsprocessed;
//		std::cout << "INFO: points processed (before): " << _pointsprocessed << "/" << mpsize << std::endl;
		int finish;
		int remaining = mpsize - _pointsprocessed;
		if( remaining > kBlockSize ) {
			finish = _pointsprocessed + kBlockSize;
		} else {
			finish = _pointsprocessed + remaining;
		}
		for (int i = start; i<finish; i++){
			if( _channels > 0 ) { PushToTalon(_mpData.GetPoint(0, i), _talonA, 0); }
			if( _channels > 1 ) { PushToTalon(_mpData.GetPoint(1, i), _talonB, 1); }
		}
		_pointsprocessed = finish;
//		std::cout << "INFO: points processed (after): " << _pointsprocessed << "/" << mpsize << std::endl;
		_blocks--;
	}
}

void MotionProfileControl::PushToTalon(TrajectoryPoint point, std::shared_ptr<TalonSRX> _talon, int side) {
	//Uncomment these to find out if the top buffer is filling up
//	if( _channels > 0 ) {
//		std::cout << "Side A top-buffer count: " << _talonA->GetMotionProfileTopLevelBufferCount() << " out of " << kTopBufferSize << std::endl;
//	}
//	if( _channels > 1 ) {
//		std::cout << "Side B top-buffer count: " << _talonB->GetMotionProfileTopLevelBufferCount() << " out of " << kTopBufferSize << std::endl;
//	}

	//negate one side because motor is inverted
	if (side == 1) {
		point.position *= -1;
		point.velocity *= -1;
	}

	//Convert pos and vel to sensor units
	point.position = point.position * kSensorUnitsPerRotation;
	point.velocity = point.velocity * kSensorUnitsPerRotation/600;

	//Push point to Talon
	ctre::phoenix::ErrorCode pushpointstatus;
	pushpointstatus = _talon->PushMotionProfileTrajectory(point);
	if( pushpointstatus != 0 ) {
		std::cout << "  push point status: " << pushpointstatus << "\n";
	}
}

void MotionProfileControl::start(){
	//signal to control() to start filling
	_bStart = true;

	//Put Talons in Motion Profile Mode
	if( _channels > 0 ) { _talonA->Set(ControlMode::MotionProfile, _setValue); }
	if( _channels > 1 ) { _talonB->Set(ControlMode::MotionProfile, _setValue); }
}

void MotionProfileControl::stop(){
	std::cout << "MotionProfileControl: stop" << std::endl;
	//Reset variables and objects (controllers, sensors, etc)
	reset();
	isRunning = false;

	//Put talons back in manual mode
	if( _channels > 0 ) { _talonA->Set(ControlMode::PercentOutput, 0); }
	if( _channels > 1 ) { _talonB->Set(ControlMode::PercentOutput, 0); }
}

void MotionProfileControl::load(){
	std::cout << "MotionProfileControl: load" << std::endl;
	_mpData.ReadMotionProfile(_profile);
}

void MotionProfileControl::initialise(){

	std::cout << "MotionProfileControl: initialise" << std::endl;
	//Put Talons in MP mode
	if( _channels > 0 ) { _talonA->Set(ControlMode::MotionProfile, 0); }
	if( _channels > 1 ) { _talonB->Set(ControlMode::MotionProfile, 0); }

	//Setup start vars (used in execute())
	firsttimearound = true;
	execounter = 0;
	isRunning = true;
}

void MotionProfileControl::execute(){
	//Determine what to do based on state
	control();
	SmartDashboard::PutNumber("_loopTimeout", _loopTimeout);

	//Set talons to take motion profile points
	SetValueMotionProfile setOutput = GetSetValue();
	if( _channels > 0 ) { _talonA->Set(ControlMode::MotionProfile, setOutput); }
	if( _channels > 1 ) { _talonB->Set(ControlMode::MotionProfile, setOutput); }

	//Start filling
	if( firsttimearound ) {
		start();
		firsttimearound = false;
	}
}

SetValueMotionProfile MotionProfileControl::GetSetValue(){
	//Return Disable, Enable, or Hold
	return _setValue;
}

bool MotionProfileControl::IsRunning(){
	return isRunning;
}
