#ifndef SPEEDYBLUETOOTHH
#define SPEEDYBLUETOOTHH

#include "Arduino.h"

namespace Speedy {
	class Bluetooth {
		// Bluetooth Communication class, more precisely serial over bluetooth
	public:
		Bluetooth();	// Constructor initializes the serial port
		char receive(); // Receive a character, returns '0' if nothing is received
	};

}

#endif
