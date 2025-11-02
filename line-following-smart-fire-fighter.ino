

// Define all the pins of the motor driver module


#define enaPin 3
#define in1 5
#define in2 6
#define in3 9
#define in4 10
#define enbPin 11
#define IRsensorL 12
#define IRsensorR 4
#define relay 2
#define LED 13
#define buzzer 1

#define flameSensor 7
#define MOTOR_SPEED 180



void setup() {

  Serial.begin(9600);
  TCCR0B = TCCR0B & B11111000 | B00000010 ;

  // Configure the pins as INPUT or OUTPUT
  
  pinMode(enaPin, OUTPUT);
  pinMode(enbPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(IRsensorL,INPUT);
  pinMode(IRsensorR, INPUT);
  pinMode(flameSensor,INPUT);
  pinMode(relay,OUTPUT);
  
  rotateMotor(0,0);

}

void loop() {
  
  int rightIRSensorValue = digitalRead(IRsensorR);
  int leftIRSensorValue = digitalRead(IRsensorL);

  int flamesensorValue = digitalRead(flameSensor);

  Serial.println(flamesensorValue);


  /*
  if (flamesensorValue == 1) {
    rotateMotor(0, 0);
    digitalWrite(LED,HIGH);
    BuzzerTune();
    digitalWrite(relay,HIGH);
    delay(3000);
    digitalWrite(relay,LOW);
  }

  else if (flamesensorValue == 0) {
    //If none of the sensors detects black line, then go straight
    if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
      rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
    }
  //If right sensor detects black line, then turn right
    else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
    }
  //If left sensor detects black line, then turn left  
    else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH ){
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
    } 
  //If both the sensors detect black line, then stop 
    else {
    rotateMotor(0, 0);
    }
  }*/
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);      
  }
  else
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);      
  }
  else 
  {
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);      
  }
  analogWrite(enaPin, abs(rightMotorSpeed));
  analogWrite(enbPin, abs(leftMotorSpeed));    
}

void BuzzerTune() {
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}

