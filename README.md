# SpeedyCar
Arduino code for my simple stateless RC car. 
Dumb autopilot included. 

[Pictures + Video + Cat reaction](https://photos.app.goo.gl/iQyMyCzuSLjvLZnt7)

The car has 2 motor drivers (model below in parts list) driving 4 motors, one per wheel. Power is by 16 AA batteries in 2 banks, one per motor driver. One of those banks also powers the Arduino and the rest of the car.

The sensor is an ultrasonic sensor mounted on a servo, so it can swivel and "look around". I also mounted an IR obstacle sensor, but ended up not using it due to its range being too small. 

RC Control is provided by a wonderful Bluetooth module. It handles all the pairing and details on it's own, leaving you with an easy to use serial port for communication. I opted for a simple 1 character protocol, for example receiving 'F' would make the car go forwards, 'B' backwards and so on. I used a remote control Bluetooth app to control it from my phone (there are many). Remember to set the commands to repeat when you press a button on the app, the car's software has no state so it needs to be told what to do constantly.

The autopilot looks left, right and front with the ultrasonic sensor, then goes in the direction with the most free space. Nothing complicated, in keeping with the need for simplicity.

Notes:
- 16 AA Batteries is a bit overkill, and heavy, but i wanted it to be fast.
- I ended up not using the IR obstacle sensor. It's range is too small. Did make for a nice front bumper though.
- Mounting a ultrasonic sensor on a servo was needlessly complicated. Better to just buy more and install them facing in the needed direction.
- The mega2560 is overkill, a cheap Arduino should be enough. It's what I had on hand though.
- Ultrasonic sensors aren't accurate enough, it would see walls, but not chair legs. Also the cheap one i bought would randomly output garbage. Some kind of signal processing would make it more reliable.

Parts:

    1 Elegoo MEGA2560
    16 AA Batteries + 2 Holders
    1 TE174 IR Obstacle Sensor
    1 HC-SR04 Ultrasonic Sensor + Mount
    1 Servo (the ultrasonic sensor is mounted on this)
    2 L298N Motor Drivers
    1 HC-05 Bluetooth module
    Chassis with 4 wheels and motors. I used the Edilights one.
    Wires
