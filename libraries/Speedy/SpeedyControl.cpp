#include "SpeedyControl.h"

namespace Speedy {
	Control::Control() {
		car = new Car();
		bluetooth = new Bluetooth();	// Initialize bluetooth antenna
		autoPilotEnabled = false;		// Initially the autopilot is disabled
		Serial.begin(9600);				// Initialize serial port, for flashing the firmware
		car->servo->write(SERVOFRONT);	// Point the sonar forwards
		
		frontDist = 10001;				// Initial obstacle distance to uh really far away
		leftDist = 10000;				// These will get updated from sensor readings when
		rightDist = 10000;				// the autopilot is enabled.
		
		timer = millis();				// Initialize timers
		lastServoMove = millis();
	}
	
	Control::~Control() {
		delete car;
		delete bluetooth;
	}
	
	void Control::runCar() {				// Main loop function
		char data = bluetooth->receive();	// Get bluetooth coms
		timer = millis();					// Update tier
		
		// Enable/disable autopilot according to data received,
		// then run the autopilot or remote control
		if (data == BTENABLEAUTO) {
			autoPilotEnabled = true;
		}
		if (data == BTDISABLEAUTO) {
			autoPilotEnabled = false;
		}
		
		if (autoPilotEnabled) {
			look();		// Update sensor readings (dist vars)
			autoPilot();
		}
		else remoteControl(data);

	}
	
	void Control::remoteControl(char data) {
		// Remote control handling function
		// Interpret Bluetooth data
		switch (data) {
			case BTFORWARD:
				car->accelerate(MAXTHROTTLE);
				break;
			case BTREVERSE:
				car->reverse(MAXTHROTTLE);
				break;
			case BTLEFT:
				car->turnLeft(MAXTHROTTLE);
				break;
			case BTRIGHT:
				car->turnRight(MAXTHROTTLE);
				break;
			case BTSTOP:
				car->stop();
				break;
			default:
				break;
		}
	}	
	
	void Control::autoPilot() {
		// Simple autopilot function
		if (frontDist < 20) {	// If there is an obstacle in front, full speed reverse
			car->reverse(MAXTHROTTLE);
			return;
		}
		
		// Move towards the direction with the most free space
		if (frontDist > leftDist && frontDist > rightDist) car->accelerate(AUTOPILOTTHROTTLE);
		if (leftDist > frontDist && leftDist > rightDist) car->turnLeft(MAXTHROTTLE);
		if (rightDist > frontDist && rightDist > leftDist) car->turnRight(MAXTHROTTLE);
	}
	
	void Control::look()	{
		// Look front, right and left with the sonar sensor, and update dist vars
		if (lastServoMove + SERVODELAY > millis()) return; // Skip if it moved
			// recently, the servo takes some time to get in position

		// If the servo is in position (front, right or left)
		// Send a pulse, and update dist var, start to move the servo
		// in another position and update timing var
		if (car->servo->read() == SERVOFRONT) {
			frontDist = car->sonar->pulse();
			car->servo->write(SERVORIGHT);
			lastServoMove = timer;
		}
		else if (car->servo->read() == SERVORIGHT) {
			rightDist = car->sonar->pulse();
			car->servo->write(SERVOLEFT);
			lastServoMove = timer;
			return;
		}
		else if (car->servo->read() == SERVOLEFT) {
			leftDist = car->sonar->pulse();
			car->servo->write(SERVOFRONT);
			lastServoMove = timer;
		}
	}
}

