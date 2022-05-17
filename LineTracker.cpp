// 
// 
// 

#include "LineTracker.h"
#include "LineSensor.h"

LineTracker::LineTracker(LineSensor** sensors, uint8_t sensorsCount)
{
	this->sensors = sensors;
	this->sensorsCount = sensorsCount;

	for (uint8_t i = 0; i < sensorsCount; i++)
	{
		if (abs(sensors[i]->getValue()) > maxError)
			maxError = sensors[i]->getValue();
	}
}

int16_t LineTracker::getError()
{
	int16_t error = 0;
	for (uint8_t i = 0; i < sensorsCount; i++)
	{
		error += sensors[i]->getValue();
	}

	if (error == 0 && abs(lastError) >= maxError) {
		error = lastError;
	}

	lastError = error;

	return error;
}
