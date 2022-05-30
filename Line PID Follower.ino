#include "Accelerator.h"
#include "LineTracker.h"
#include "LineSensor.h"
#include "Robot.h"
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "MotorRegulator.h"
#include "Accelerator.h"
#include <TimerOne.h>

void onLeftEncoder();
void onRightEncoder();

#define PIDUpdateRate 0.02f

Encoder* leftEncoder = new Encoder(3, onLeftEncoder, 40);
Encoder* rightEncoder = new Encoder(2, onRightEncoder, 40);

Motor* leftMotor = new Motor(12, 4, 5);
Motor* rightMotor = new Motor(10, 8, 13);

PID* leftMotorPID = new PID(2, 0, 0);
PID* rightMotorPID = new PID(2, 0, 0);

MotorRegulator* leftMotorRegulator = new MotorRegulator(leftMotor, leftEncoder, leftMotorPID);
MotorRegulator* rightMotorRegulator = new MotorRegulator(rightMotor, rightEncoder, rightMotorPID);

LineSensor** sensors = new LineSensor*[4]{
		new LineSensor(A0, 20),
		new LineSensor(A1, 10),
		new LineSensor(A2, -10),
		new LineSensor(A3, -20)
};
LineTracker* lineTracker = new LineTracker(sensors, 4);
PID* linePID = new PID(0.3f, 0.0f, 0.005f);

Accelerator* accelerator = new Accelerator(2.0f, 8.0f, 12.0f, 0.02f);

Robot* robot = new Robot(leftMotorRegulator, rightMotorRegulator, linePID, lineTracker, accelerator);


void setup()
{
	leftMotorPID->setMaxMin(-255, 255);
	rightMotorPID->setMaxMin(-255, 255);
	linePID->setMaxMin(-255, 255);

	Timer1.initialize(PIDUpdateRate * 1000000);
	Timer1.attachInterrupt(onTimer);

	Serial.begin(9600);
}

void loop()
{

}

void onTimer() {
	robot->update(PIDUpdateRate);
}

void onLeftEncoder() {
	leftEncoder->onTick();
}

void onRightEncoder() {
	rightEncoder->onTick();
}
