// ALL THE CODE IS IN THE LIBRARIES FOLDER
// This just runs it

#include <SpeedyBluetooth.h>
#include <SpeedySonar.h>
#include <SpeedyCar.h>
#include <SpeedyControl.h>
#include <SpeedyPins.h>
#include <SpeedyObstacleDetector.h>
#include <SpeedyMotorDriver.h>

Speedy::Control* cnt;

void setup() {
  cnt = new Speedy::Control();
}

void loop() {
  cnt->runCar();
}
