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

class Robot {
public:
	Robot(MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator, PID* linePID, LineTracker* lineTracker, float targetVelocity);
	void update(float updateRate);

private:
	MotorRegulator* leftMotorRegulator;
	MotorRegulator* rightMotorRegulator;
	PID* linePID;
	LineTracker* lineTracker;
	float targetVelocity = 0.0f;
};


extern Robot ;

#endif

