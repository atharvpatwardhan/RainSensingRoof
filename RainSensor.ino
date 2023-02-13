#include <Servo.h>

Servo motor;

void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  motor.attach(9);
}

void loop(){
  int pos = 0;
  motor.write(pos);
  int value = analogRead(A3);

  if(value < 300){
    if(pos==0){
      pos = 180;
      motor.write(pos);
    }
    digitalWrite(2,HIGH);
    Serial.print("Heavy Rain LED ON");

  }
  else if(value>300){
    if(pos==180){
      pos = 0;
      motor.write(180);
    }
    digitalWrite(2,LOW);

  }
}
