// Accelerator.h

#ifndef _ACCELERATOR_h
#define _ACCELERATOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Accelerator {
public:
	Accelerator(float min, float max, float acceleration, float deaccelerateKoefficient);
	float getVelocity(float error, float deltaTime);
private:
	float min = 0.0f;
	float max = 0.0f;
	float acceleration = 0.0f;
	float deaccelerateKoefficient = 0.0f;
	float moveToward(float current, float target, float delta);
	float currentVelocity = 0.0f;
};


#endif