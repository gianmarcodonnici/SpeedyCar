#include "Arduino.h"
#include "SpeedyObstacleDetector.h"

namespace Speedy {
	ObstacleDetector::ObstacleDetector(int pinsig) : pinSignal(pinsig) {
		pinMode(pinSignal, INPUT);
	}
	
	bool ObstacleDetector::detect() { 
		// Return true if an obstacle is detected
		int val = digitalRead(pinSignal);
		return val != HIGH;
	}
}
