#ifndef SPEEDYOBSTACLEDETECTORH
#define SPEEDYOBSTACLEDETECTORH

#include "Arduino.h"

namespace Speedy {
	class ObstacleDetector {
	private:
		int pinSignal;
	public:
		ObstacleDetector(int pinsig);
		bool detect();		//Returns true if an obstacle is detected
	};
}

#endif
