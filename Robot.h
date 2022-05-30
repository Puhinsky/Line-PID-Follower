// Robot.h

#ifndef _ROBOT_h
#define _ROBOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MotorRegulator.h"
#include "LineTracker.h"
#include "PID.h"
#include "Accelerator.h"

class Robot {
public:
	Robot(MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator, PID* linePID, LineTracker* lineTracker, Accelerator* accelerator);
	void update(float updateRate);

private:
	MotorRegulator* leftMotorRegulator;
	MotorRegulator* rightMotorRegulator;
	PID* linePID;
	LineTracker* lineTracker;
	Accelerator* accelerator;
};


extern Robot ;

#endif

