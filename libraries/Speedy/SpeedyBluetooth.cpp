#include "SpeedyBluetooth.h"
#include "Arduino.h"

namespace Speedy {
	Bluetooth::Bluetooth() {		// Initialize serial port at 9600 baud
		Serial1.begin(9600);
	}
	
	char Bluetooth::receive() {		// return a character if available, else 0
		if (Serial1.available()) {
			return Serial1.read();
		}
		else return '0';
	}
}
