// 
// 
// 

#include "LineSensor.h"

LineSensor::LineSensor(uint8_t pin, int8_t weight)
{
	pinMode(pin, INPUT_PULLUP);
	this->pin = pin;
	this->weight = weight;
}

int8_t LineSensor::getValue()
{
	return digitalRead(pin) * weight;
}

int8_t LineSensor::getWeight()
{
	return weight;
}

bool LineSensor::onLine()
{
	return !digitalRead(pin);
}
