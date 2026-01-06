 <div align="justify"> 

## __WHAT IT DOES__
This is a line following smart fire fighter. <br>
 - It acts as a line following robot (to follow a specific path).
 - It detects fire/flame.
 - When fire is detected, it stops and sprays water.

<br>

## __COMPONENTS USED__

1. Arduino UNO x1.
2. L298N Motor Driver Module x1.
3. Small Breadboard x1.
4. 6V Gear Motor x4.
5. IR Sensor x2.
6. IR Flame Sensor x1.
7. 3.7V 3500mA 18650 Li-ion Rechargeable Battery x2.
8. Switch x1.
9. 5V Relay Module x1.
10. 9V Battery x1.
11. 3-6V DC Motor Submersible Pump x1.
12. Jumper wires (as needed).
13. Buzzer x1.

## __EXTRA COMPONENTS NEEDED__

14. 4 Wheel Car Chassis Kit (this will include 4 Gear Motors) x1.
15. Battery chargers.
16. Battery holders, brackets, protective case, etc. (if needed).
17. Water container to fill water needed for spraying (should be very light).
18. Long tube to spray water.
19. Black tape (to make the path for following).
20. Cardboards, color papers, etc. (for props and decorations)

_IMPORTANT NOTE: Do NOT make the robot heavy as this can put more load on the gear motors and cause the robot to NOT move._

<br>

## __THE THEORY BEHIND__

1. _How is everything powered up?_ <br>
   - The rechargeable battery powers up the L298N motor driver module. As the total voltage of the batteries do not exceed 12v, the L298N's jumper is not removed. This makes the 5V pin of the L298N to act as an output. This output is used to give power to the Arduino and the relay module. Then through the 5V pin of the Arduino, the rest of the sensors i.e. 2 IR sensors and the flame sensor are powered up. <br>
  
2. _How does the robot follow the line?_
   - The IR sensors consists of an emitter (the white LED) and a receiver (the black photodiode). Since this is an active IR sensor, the infra-red rays are emitted and received by the IR sensor itself. The emitter sends light and if the surface where the light falls is white or any other light color, most of the light bounces or reflects back and the receiver gets the light back. This gives a strong signal (HIGH/1). When the light from the emitter falls on a black surface, it gets absorbed and very little to no light get reflected back to the receiver, giving out a weak signal (LOW/0). These readings/signals can be used to control the motor as required.
  
3. _How does the water get sprayed?_
   - The flame sensor detectes the IR emitted by the flame, giving out a strong signal (HIGH/1). When a flame is detected, it sends the signal to the Arduino. Arduino sends a signal to the gear motors to stop and for the buzzers to ring. Arduino also sends a signal to the relay module. The relay closes the switch, turning on the motor pump.


<br>

## __TIPS__

1. Use high quality batteries for efficiency.
2. Remove the wire connected to the VIN pin of Arduino before connecting the Arduino to the PC/laptop to upload the code. Once the code is uploaded, disconnect the Arduino from the PC/laptop and connect the wire back to the VIN pin of the Arduino. This is to prevent too much voltage flowing into the Arduino via the laptop and the batteries.
3. Always check the value given by the flame sensor via the Serial Monitor and change the threshold value accordingly. Threshold value may change according to your environment due to differences in the amount of light in the room.
4. The most common issue while making robotics projects is that the wires break too soon. Either better wires instead of jumper wires should be used, or use a multimeter to constantly check if the jumper wires are in good condition.

<br>

## __PROBLEMS FACED AND SOLUTIONS__

1. _Why does my relay keep switching on when no fire is detected?_ <br>
   There are 2 main reasons for this; <br>
      - The wires of the flame sensor are loose, making the flame sensor switch on and off. This would give lower and higher values simultaneously, causing the relay to switch on. Secure the wires with strong tape or by soldering.<br>
      - The sensitivity of the flame sensor is too high and would even detect lights/sunlight in the room. Therefore, either reduce the sensitivity by rotating the potentiometer/screw on the sensor, or give a very small value as the threshold value in the code for detecting fire. <br>

2. _Why do wheels rotate when off the floor, but not when on the floor?_ <br>
   If wheels are rotating when off the floor, this means that there us no problem with the supplied voltage or current. There could be 3 reasons for this:
      - It could be due to the heavy load the gear motors have when on the floor. For this reason, make the robot as light as you can and do not fill with too much water for spraying. <br>
      - The wheels might not be rotating in the correct directions. If the 2 wheels on the left or right side are rotating opposite to each other when it is supposed to move forward, then the robot will not move. When both wheels are moving opposite to each other, the direction becomes neutral and the robot stops moving. Always ensure, the wheels are rotating in the correct directions off the floor, before keeping the robot on the floor. <br>
      - Check if the wheels are not aligned or stable and feels shakey when kept on the floor. If it is so, make sure to purchase a good quality chassis and check if all the screws used to fix the gear motors to the chassis are properly tightened. <br>

3. _Why are the wheels not moving at all, even off the floor?_ <br>
   - This could be due to several reasons from wrong connections, broken wires to short circuited boards. But if all is well and if the issue still persists, something else could be wrong. Check if the flame sensor and the 2 IR sensors given power through the Arduino, have thier power LEDs switched on. If so, the issue is due to the rechargeable batteries not being able to give enough power to the wheels. Recharge the batteries atleast till they reach a total voltage of 7.4V and try again. <br>

4. _Why are the IR sensors not detecting the black path, causing the robot to not follow the line?_ <br>
  There could be 2 main reasons for this; <br>
   - If you are using black paper for the path, the IR sensors sometimes do not detect it as black when the environment is too bright. As a solution, it is always best to use black tape or black paint to make the path, as these would give the darkest shade of black to the path, making the IR sensors detect the black even at brighter environments. <br>
   - The wheels might be rotating too fast. So by the time the IR sensor detects that the robot is out of the path, the reaction time is too late. This causes the robot to move out of the path. To use slower or varying speed, the ENA and ENB pins of the L298N should be connected to the PWM pins of the Arduino.

5. _Why does the motor pump not pump water?_ <br>
   - If the connections are all good and it still does not work, the issue could be with the 9V battery. There might not be enough voltage to poer up the motor pump. Check the voltage of the battery with a multimeter. If it iss lower than 4v, replace the battery with a new one and try again. <br>

6. _Why are the wheels only moving at full speed instead of varying or reduced speeds?_ <br>
   - The ENA and ENB pins of the L298N should be connected to PWM pins of the Arduino. Only this allows speed to vary as given in the code. <br>






</div>
   

   
