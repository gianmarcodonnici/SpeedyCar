#ifndef SPEEDYMOTORDRIVERH
#define SPEEDYMOTORDRIVERH

#include "Arduino.h"

namespace Speedy {
	class MotorDriver {
		// Motor driver class, manages motors of 2 wheels (A and B)
	private:
		// Motor pins
		int pinEnA;
		int pinEnB;
		int pinIn1;
		int pinIn2;
		int pinIn3;
		int pinIn4; 
	public:
		MotorDriver(int ena, int enb, int in1, int in2, int in3, int in4);
		
		// Wheel throttle (pwm signal)
		void throttleA(unsigned char throttle);
		void throttleB(unsigned char throttle);
		
		// Set direction of rotation
		void goForwardA(bool forward);
		void goForwardB(bool forward);
	};
}

#endif
