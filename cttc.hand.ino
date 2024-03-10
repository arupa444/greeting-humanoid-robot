#include<Servo.h> 
Servo myservo1;
Servo myservo2;
int pinState = LOW;
int startingdegree=0;
int joiningdegree=90;
void setup() {
  myservo1.attach(6);// Servo 1
  myservo2.attach(10);// Servo 2
  // put your setup code here, to run once:
  pinMode(2,INPUT_PULLUP);// limit switch 1 for up
  pinMode(3,INPUT_PULLUP);// limit switch 2 for up
  pinMode(4,OUTPUT);// relay for motor 1 Reverse when only HIGH
  pinMode(5,OUTPUT);// relay for motor 2 Reverse when only HIGH
  pinMode(13,OUTPUT);// relay for motor 1 forward when only HIGH
  pinMode(12,OUTPUT);// relay for motor 2 forward when only HIGH
  pinMode(8,INPUT_PULLUP);// limit switch 1 for down
  pinMode(9,INPUT_PULLUP);// limit switch 2 for down
  pinMode(11,INPUT);// sensor signal
  Serial.begin(9600);// for serial monitor
}

void loop() {/*
  analogWrite(,10);// (pin(3,5,6,9,10,11),speed(0-255)) 
  analogWrite(,10);// (pin(3,5,6,9,10,11),speed(0-255))
  analogWrite(,10);// (pin(3,5,6,9,10,11),speed(0-255))
  analogWrite(,10);// (pin(3,5,6,9,10,11),speed(0-255))
*/
  while((digitalRead(2)==HIGH)||(digitalRead(3)==HIGH)){
      Serial.println("INSIDE WHILE LOOP");
      if(digitalRead(2)==HIGH){
        Serial.println("4 is HIGH");
          digitalWrite(4,HIGH);
          digitalWrite(13,LOW);
        }
      else{
          digitalWrite(4,LOW);
          digitalWrite(13,LOW);
        Serial.println("4 is LOW");
        }
      if(digitalRead(3)==HIGH){
        Serial.println("5 is HIGH");
          digitalWrite(5,HIGH);
          digitalWrite(12,LOW);
        }
      else{
        Serial.println("5 is LOW");
          digitalWrite(5,LOW);
          digitalWrite(12,LOW);
        }  
    startingdegree=0;
    joiningdegree=90;
    }
    for(;startingdegree<=joiningdegree;--joiningdegree)
    {
      myservo1.write(joiningdegree);
      myservo2.write(joiningdegree);
      delay(60);
    }
    Serial.println("OUTSIDE WHILE LOOP");
    if(digitalRead(11)==LOW){
      pinState = HIGH;
      Serial.println("PIN STATE IS HIGH MEANS IT IS ACTIVE");
      }
      else{
        pinState = LOW;
      Serial.println("PIN STATE IS LOW MEANS IT IS DEACTIVE");
        }
    while(pinState == HIGH){
      while((digitalRead(8)==HIGH)||(digitalRead(9)==HIGH)){
        Serial.println("INSIDE ANOTHER LOOP");
        if(digitalRead(8)==HIGH){
          Serial.println("13 is HIGH");
          digitalWrite(13,HIGH);
          digitalWrite(4,LOW);
          }
        else{
          Serial.println("13 is LOW");
          digitalWrite(13,LOW);
          digitalWrite(4,LOW);
          }
        if(digitalRead(9)==HIGH){
          Serial.println("12 is HIGH");
          digitalWrite(12,HIGH);
          digitalWrite(5,LOW);
          }
        else{
          Serial.println("12 is LOW");
          digitalWrite(12,LOW);
          digitalWrite(5,LOW);
        }
        }
       startingdegree=0;
       joiningdegree=90;
       pinState = LOW;
        for(;joiningdegree>=startingdegree;++startingdegree)
        {
            myservo1.write(startingdegree);
            myservo2.write(startingdegree);
            delay(60);
        }
    }
      delay(2000);
}
