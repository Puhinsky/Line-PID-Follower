// LineTracker.h

#ifndef _LINETRACKER_h
#define _LINETRACKER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LineSensor.h"

class LineTracker {
public:
	LineTracker(LineSensor** sensors, uint8_t sensorsCount);
	int16_t getError();
private:
	LineSensor** sensors;
	uint8_t sensorsCount = 0;
	int16_t lastError = 0;
	uint8_t maxError = 0;
};

extern LineTracker;

#endif

