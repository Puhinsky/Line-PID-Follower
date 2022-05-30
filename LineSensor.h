// LineSensor.h

#ifndef _LINESENSOR_h
#define _LINESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class LineSensor {
public:
	LineSensor(uint8_t pin, int8_t weight);
	int8_t getValue();
	int8_t getWeight();
	bool onLine();
private:
	uint8_t pin = 0;
	int8_t weight = 0;
};

extern LineSensor;

#endif

