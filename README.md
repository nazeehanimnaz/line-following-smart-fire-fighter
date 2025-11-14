* COMPONENTS USED

1. Arduino UNO x1
2. L298N Motor Driver Module x1
3. Small Breadboard x1
4. 6V Gear Motor x4
5. IR Sensor x2
6. Flame Sensor x1
7. Buzzer x1
8. 3.7V 3500mA 18650 Li-ion Rechargeable Battery x2
9. Switch x1
10. 5V Relay Module x1
11. 9V Battery x1
12. DC Motor Pump x1

* TIPS

1. Use high quality batteries for efficiency.
2. Remove the wire connected to the VIN pin of Arduino before connecting the Arduino to the PC/laptop to upload the code. Once the code is uploaded, disconnect the Arduino from the PC/laptop and connect the wire back to the VIN pin of the Arduino. This is to prevent too much voltage flowing into the Arduino via the laptop and the batteries.
3. Always check the value given by the flame sensor via the Serial Monitor and change the threshold value accordingly. Threshold value may change according to your environment due to differences in the amount of light in the room.

* PROBLEMS FACED AND SOLUTIONS

1. P: Why does my relay keep switching on when no fire is detected? <br>
   S: There are 2 main reasons for this; <br>
       - The wires of the flame sensor are loose, making the flame sensor switch on and off. This would give lower and higher values simultaneously, causing the relay to switch on. Secure the wires with strong tape or by soldering.<br>
       - The sensitivity of the flame sensor is too high and would even detect lights/sunlight in the room. Therefore, either reduce the sensitivity by rotating the potentiometer/screw on the sensor, or give a very small value as the threshold value in the code for detecting fire. <br>

2. P: Wheels
   
