#ifndef SPEEDYCARH
#define SPEEDYCARH

#include "Arduino.h"
#include "Servo.h"

#include <SpeedySonar.h>
#include <SpeedyPins.h>
#include <SpeedyObstacleDetector.h>
#include <SpeedyMotorDriver.h>

namespace Speedy {
	class Car {
		// Main car classes, holds pointers to sensors and drives, initializes
		// them and exposes functions to, well, make the car do things.
	private:
		MotorDriver* driverL;	// Left wheels Driver
		MotorDriver* driverR;	// Right wheels drivers
		
	public:
		Sonar* sonar;			// Ultrasonic sensor
		Servo* servo;			// Ultrasonic sensor mount servo
		ObstacleDetector* obs;	// Obstacle detector
		
		Car();
		~Car();
		
		void turnLeft(unsigned char throttle);		// Turn car left at throttle speed
		void turnRight(unsigned char throttle);		// Turm car right at throttle speed
		void accelerate(unsigned char throttle);	// Move forwards at throttle speed
		void reverse(unsigned char throttle);		// Move backwards at throttle speed
		void stop();								// Stop Moving
	};
}

#endif
