// 
// 
// 

#include "Accelerator.h"

Accelerator::Accelerator(float min, float max, float acceleration, float deaccelerateKoefficient)
{
	this->min = min;
	this->max = max;
	this->acceleration = acceleration;
	this->deaccelerateKoefficient = deaccelerateKoefficient;
}

float Accelerator::getVelocity(float error, float deltaTime)
{
	if (error == 0) {
		currentVelocity = moveToward(currentVelocity, max, acceleration * deltaTime);
	}
	else {
		currentVelocity = moveToward(currentVelocity, min, deaccelerateKoefficient * abs(error));
	}
	return currentVelocity;
}



float Accelerator::moveToward(float current, float target, float delta)
{
	if (current < target)
		current = min(current + delta, target);
	else
		current = max(current - delta, target);
	return current;
}
