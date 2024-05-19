//Written By Nikodem Bartnik - nikodembartnik.plSerial.begin(9600); 
#define STEPPER_PIN_1 27
#define STEPPER_PIN_2 14
#define STEPPER_PIN_3 12
#define STEPPER_PIN_4 13
#define MOTION_PIN 35
#define LED_PIN 34
#define BLUE_LED 33
#define GREEN_LED 25
#define RED_LED 32
int val = 0;
int step_number = 0;
int activated_count = 0;
bool activated = false;
#include <iostream>
using namespace std;

void setup() {
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);
pinMode(LED_PIN, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
pinMode(RED_LED, OUTPUT);
pinMode(MOTION_PIN, INPUT);
}



void loop() { 
  val = digitalRead(MOTION_PIN);
  Serial.println("val" + val);
 if (val == HIGH && !activated){
  activated = true;
 }

 if (activated){
  OneStep(false);
  delay(2);

  activated_count++;
  Serial.println("activated_count" + activated_count);

  if(activated_count>10){
    activated_count = 0;
    activated = false;
  }
 }
}


void OneStep(bool dir){
   digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(BLUE_LED, HIGH);  // turn the LED on (HIGH is the voltage leve
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
 digitalWrite(RED_LED, HIGH);  // turn the LED on (HIGH is the voltage leve
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
 

  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(GREEN_LED, HIGH);  // turn the LED on (HIGH is the voltage leve
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(RED_LED, LOW);  // turn the LED on (HIGH is the voltage leve
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(BLUE_LED, HIGH);  // turn the LED on (HIGH is the voltage leve
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(RED_LED, HIGH);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}