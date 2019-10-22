#include "Arduino.h"
#include "SpeedySonar.h"

int Speedy::Sonar::pulse() {
	long duration;		// Pulse duration
	int distance;		// Calculated distance

	// 10 clean microsenconds of HIGH on trigger pin will trigger a pulse
	digitalWrite(pinTrigger, LOW);	// Set pin to low and wait 
	delayMicroseconds(2);			// to avoid premature pulse
	digitalWrite(pinTrigger, HIGH); // Send Pulse trigger
	delayMicroseconds(10);
	digitalWrite(pinTrigger, LOW);	// Reset pin

	//retrieve echo time
	duration = pulseIn(pinEcho, HIGH); // Echo time in microseconds

	// Calculate distance in cm (speed of sound = 0.034cm per microsecond
	// divided by 2 to account for round trip)
	distance = duration * 0.034/2;

	return distance;
}
