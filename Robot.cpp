// 
// 
// 

#include "Robot.h"
#include "PID.h"

Robot::Robot(MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator, PID* linePID, LineTracker* lineTracker, float targetVelocity)
{
	this->leftMotorRegulator = leftMotorRegulator;
	this->rightMotorRegulator = rightMotorRegulator;
	this->linePID = linePID;
	this->lineTracker = lineTracker;
	this->targetVelocity = targetVelocity;

	this->linePID->targetValue = 0.0f;
}

void Robot::update(float updateRate)
{
	linePID->calculate(lineTracker->getError(), updateRate);

	leftMotorRegulator->setVelocity(targetVelocity + linePID->result);
	rightMotorRegulator->setVelocity(targetVelocity - linePID->result);

	leftMotorRegulator->update(updateRate);
	rightMotorRegulator->update(updateRate);
}
