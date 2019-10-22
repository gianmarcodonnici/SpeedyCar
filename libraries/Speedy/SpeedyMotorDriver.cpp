#include "SpeedyMotorDriver.h"
#include "Arduino.h"

namespace Speedy {

	MotorDriver::MotorDriver(int ena, int enb, int in1, int in2, int in3, int in4)
		// Set pins
		: pinEnA(ena), pinEnB(enb), pinIn1(in1), pinIn2(in2), pinIn3(in3), pinIn4(in4)
	{
		// Set pinmodes
		pinMode(pinEnA, OUTPUT);
		pinMode(pinEnB, OUTPUT);
		pinMode(pinIn1, OUTPUT);
		pinMode(pinIn2, OUTPUT);
		pinMode(pinIn3, OUTPUT);
		pinMode(pinIn4, OUTPUT);
		
		// Set initial state
		throttleA(0);
		throttleB(0);
		goForwardA(true);
		goForwardB(true);
	}
	
	void MotorDriver::throttleA(unsigned char throttle) {
		// Set throttle for wheel A
		analogWrite(pinEnA, throttle);
	}
	
	void MotorDriver::throttleB(unsigned char throttle) {
		// Set throttle for wheel B
		analogWrite(pinEnB, throttle);
	}
	
	void MotorDriver::goForwardA(bool forward) {
		if (!forward) {			
		//	If pin1 is low and pin2 is high the motor 
		//	spins forwards, and if pin1 is high and pin2 is low it spins in reverse
			digitalWrite(pinIn1, LOW);
			digitalWrite(pinIn2, HIGH);	
		} else {
			digitalWrite(pinIn1, HIGH);
			digitalWrite(pinIn2, LOW);	
		}
	}
	
	void MotorDriver::goForwardB(bool forward) {
		if (!forward) {			
		// If pin1 is low and pin2 is high the motor 
		// spins forwards, and if pin1 is high and pin2 is low it spins in reverse
			digitalWrite(pinIn3, LOW);
			digitalWrite(pinIn4, HIGH);	
		} else {
			digitalWrite(pinIn3, HIGH);
			digitalWrite(pinIn4, LOW);	
		}
	}
	}	
	


