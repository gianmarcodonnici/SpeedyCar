#ifndef SPEEDYCONTROLH
#define SPEEDYCONTROLH

#include <SpeedyBluetooth.h>
#include <SpeedyPins.h>
#include <SpeedyCar.h>

namespace Speedy {
	class Control {
		// Speedy car controller
	private:
		Car* car;	// Car sensors and motors
		Bluetooth* bluetooth;	// Bluetooth antenna
		bool autoPilotEnabled;
		
		int frontDist;	// Distance to nearest obstacle in front. Used by the autopilot
		int leftDist;	// Distance to nearest obstacle left
		int rightDist;	// Distance to nearest obstacle right
		
		unsigned long timer;	// Servo timer, servo uses this to time moves while scanning
		unsigned long lastServoMove;	// Last time the servo moved
	public:
		Control();
		~Control();
	
		void runCar(); // Main loop function
		void remoteControl(char data);	// Remote control (through bluetooth) function
		void autoPilot();				// Autopilot
		void look();					// Look with the ultrasonic sensor. Updates dist vars
	};
}

#endif
