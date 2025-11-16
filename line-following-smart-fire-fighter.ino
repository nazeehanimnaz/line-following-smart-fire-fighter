

// Define all the pins of the motor driver module
#define enaPin 3
#define in1 5
#define in2 2
#define in3 9
#define in4 10
#define enbPin 11
#define IRsensorL 8
#define IRsensorR 7
#define relay 4
#define buzzer 13
#define flameSensor A0

#define s 130 //base speed
#define t 180//turning speed


void setup() {

  Serial.begin(9600);

  // Configure the pins as INPUT or OUTPUT
  pinMode(enaPin, OUTPUT);
  pinMode(enbPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(IRsensorL,INPUT);
  pinMode(IRsensorR, INPUT);
  pinMode(flameSensor,INPUT);
  pinMode(relay,OUTPUT);
  
  Siren();

}

void loop() {
  
  int rightIRSensorValue = digitalRead(IRsensorR);
  int leftIRSensorValue = digitalRead(IRsensorL);
  int flamesensorValue = analogRead(flameSensor);

  Serial.println(flamesensorValue);


  if (flamesensorValue < 200) {
    Stop();
    Siren();
    digitalWrite(relay,HIGH);
    delay(5000);
    digitalWrite(relay,LOW);
    Stop();
    delay(10000);
  }

  else if (flamesensorValue > 200) {
    //If none of the sensors detects black line, then go straight
    if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
      Forward();
    }
  //If right sensor detects black line, then turn right
    else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
      Right(); 
    }
  //If left sensor detects black line, then turn left  
    else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH ){
      Left();
    } 
  //If both the sensors detect black line, then stop 
    else {
      Stop();
    }
  }
}

//Funtion for buzzer tone
void Siren() {
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(500);
}

// Functions to change the direction
void Backward() {
  analogWrite(enaPin,s);
  analogWrite(enbPin,s);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

 void Forward() {
  analogWrite(enaPin,s);
  analogWrite(enbPin,s);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

 void Stop() {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void Right() {
  analogWrite(enaPin,t);
  analogWrite(enbPin,t);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void Left() {
  analogWrite(enaPin,t);
  analogWrite(enbPin,t);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}



