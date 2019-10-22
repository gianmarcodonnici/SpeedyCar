#include "SpeedyCar.h"
#include "Arduino.h"

namespace Speedy {
	Car::Car() {
		// Create all sensors and drivers using default pins (defined in SpeedyPins.h)
		sonar = new Sonar(PINSONARTRIGGER, PINSONARECHO);
		servo = new Servo();
		obs = new ObstacleDetector(PINOBSDETECTOR);
		driverL = new MotorDriver(PINDRIVERAENA, PINDRIVERAENB, PINDRIVERAIN1, PINDRIVERAIN2, PINDRIVERAIN3, PINDRIVERAIN4);
		driverR = new MotorDriver(PINDRIVERBENA, PINDRIVERBENB, PINDRIVERBIN1, PINDRIVERBIN2, PINDRIVERBIN3, PINDRIVERBIN4);
		servo->attach(PINSERVO);
		servo->write(SERVOFRONT);	// Tell servo to move the sonar to face forwards
	}
	Car::~Car() {
		delete sonar;
		delete servo;
		delete obs;
		delete driverL;
		delete driverR;
	}
	
	void Car::turnLeft(unsigned char throttle) {	// Turn car left at throttle speed
		// Zero out left wheels throttles
		driverL->throttleA(0);
		driverL->throttleB(0);
		// Set right wheels throttles to throttle
		driverR->throttleA(throttle);
		driverR->throttleB(throttle);
		// Set rotation direction of all wheels to forwards
		driverL->goForwardA(true);
		driverL->goForwardB(true);
		driverR->goForwardA(true);
		driverR->goForwardB(true);
	}

	void Car::turnRight(unsigned char throttle) {
		// Set left wheel throttles to throttle
		driverL->throttleA(throttle);
		driverL->throttleB(throttle);
		// Zero out right wheels throttles
		driverR->throttleA(0);
		driverR->throttleB(0);
		// Set rotation direction to forwards
		driverL->goForwardA(true);
		driverL->goForwardB(true);
		driverR->goForwardA(true);
		driverR->goForwardB(true);
	}

	void Car::accelerate(unsigned char throttle) {
		// Set all wheels throttle to throttle
		driverL->throttleA(throttle);
		driverL->throttleB(throttle);
		driverR->throttleA(throttle);
		driverR->throttleB(throttle);
		// Set rotation direction to forwards
		driverL->goForwardA(true);
		driverL->goForwardB(true);
		driverR->goForwardA(true);
		driverR->goForwardB(true);
	}

	void Car::reverse(unsigned char throttle) {
		// Set all wheels throttles to throttle
		driverL->throttleA(throttle);
		driverL->throttleB(throttle);
		driverR->throttleA(throttle);
		driverR->throttleB(throttle);
		// Set rotation direction to reverse
		driverL->goForwardA(false);
		driverL->goForwardB(false);
		driverR->goForwardA(false);
		driverR->goForwardB(false);
	}

	void Car::stop() {
		// Zero out all throttles
		driverL->throttleA(0);
		driverL->throttleB(0);
		driverR->throttleA(0);
		driverR->throttleB(0);
		// Reset wheel rotation direction
		driverL->goForwardA(true);
		driverL->goForwardB(true);
		driverR->goForwardA(true);
		driverR->goForwardB(true);
	}
	
}

