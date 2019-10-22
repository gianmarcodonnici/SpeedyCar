#ifndef SPEEDYSONARH
#define SPEEDYSONARH

#include "Arduino.h"

namespace Speedy {
	class Sonar {
		// Ultrasonic sensor management class
		private:
			int pinTrigger;	// Pin to trigger a pulse
			int pinEcho;	// Pin that returns echo time
		public:
			Sonar(int trig, int echo) : pinTrigger(trig), pinEcho(echo) {
				// Set pinmodes
				pinMode(pinTrigger, OUTPUT);
				pinMode(pinEcho, INPUT);
			}
			int pulse(); // Emits a pulse and return distance detected in cm
	};
}

#endif

