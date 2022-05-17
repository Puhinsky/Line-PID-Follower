// 
// 
// 

#include "Encoder.h"


Encoder::Encoder(uint8_t pin, void(*callback)(), uint8_t stepsCount) {
	pinMode(pin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(pin), callback, CHANGE);
	this->stepsCount = stepsCount;
}

void Encoder::onTick() {
	counter++;
}

void Encoder::reset() {
	counter = 0;
}

uint8_t Encoder::getCounter() {
	return counter;
}

uint8_t Encoder::getStepsCount() {
	return stepsCount;
}

Encoder ;