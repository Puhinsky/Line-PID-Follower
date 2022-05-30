// 
// 
// 

#include "Robot.h"
#include "PID.h"
#include "Accelerator.h"

Robot::Robot(MotorRegulator* leftMotorRegulator, MotorRegulator* rightMotorRegulator, PID* linePID, LineTracker* lineTracker, Accelerator* accelerator)
{
	this->leftMotorRegulator = leftMotorRegulator;
	this->rightMotorRegulator = rightMotorRegulator;
	this->linePID = linePID;
	this->lineTracker = lineTracker;
	this->accelerator = accelerator;

	this->linePID->targetValue = 0.0f;
}

void Robot::update(float updateRate)
{
	linePID->calculate(lineTracker->getError(), updateRate);

	float velocity = accelerator->getVelocity(linePID->result, updateRate);

	leftMotorRegulator->setVelocity(velocity + linePID->result);
	rightMotorRegulator->setVelocity(velocity - linePID->result);

	leftMotorRegulator->update(updateRate);
	rightMotorRegulator->update(updateRate);
}
