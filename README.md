* WHAT IT DOES

   This is a line following smart fire fighter.
     - It acts as a line following robot (to follow a specific path).
     - It detects fire/flame.
     - When fire is detected, it stops and sprays water.

<br>

* COMPONENTS USED

1. Arduino UNO x1.
2. L298N Motor Driver Module x1.
3. Small Breadboard x1.
4. 6V Gear Motor x4.
5. IR Sensor x2.
6. Flame Sensor x1.
7. 3.7V 3500mA 18650 Li-ion Rechargeable Battery x2.
8. Switch x1.
9. 5V Relay Module x1.
10. 9V Battery x1.
11. 3-6V DC Motor Submersible Pump x1.
12. Jumper wires (as needed).

* EXTRA COMPONENTS NEEDED

13. 4 Wheel Car Chassis Kit (this will include 4 Gear Motors) x1.
14. Battery chargers.
15. Battery holders, brackets, protective case, etc. (if needed).
16. Water container to fill water needed for spraying (should be very light).
17. Long tube to spray water.
18. Black tape (to make the path for following).
19. Cardboards, color papers, etc. (for props and decorations)

IMPORTANT NOTE: Do NOT make the robot heavy as this can put more load on the gear motors and cause the robot to NOT move.

<br>

* TIPS

1. Use high quality batteries for efficiency.
2. Remove the wire connected to the VIN pin of Arduino before connecting the Arduino to the PC/laptop to upload the code. Once the code is uploaded, disconnect the Arduino from the PC/laptop and connect the wire back to the VIN pin of the Arduino. This is to prevent too much voltage flowing into the Arduino via the laptop and the batteries.
3. Always check the value given by the flame sensor via the Serial Monitor and change the threshold value accordingly. Threshold value may change according to your environment due to differences in the amount of light in the room.

<br>

* PROBLEMS FACED AND SOLUTIONS

1. P: Why does my relay keep switching on when no fire is detected? <br>
   S: There are 2 main reasons for this; <br>
       - The wires of the flame sensor are loose, making the flame sensor switch on and off. This would give lower and higher values simultaneously, causing the relay to switch on. Secure the wires with strong tape or by soldering.<br>
       - The sensitivity of the flame sensor is too high and would even detect lights/sunlight in the room. Therefore, either reduce the sensitivity by rotating the potentiometer/screw on the sensor, or give a very small value as the threshold value in the code for detecting fire. <br>

2. P: Wheels
   
