#include <LiquidCrystal.h>
#define gas A0
#define relay 6
int alc=0;
int motor1_ena = 3;
int motor1_in1 = 4;
int motor1_in2 = 5;
int speed=255;
void setup() 
{
  pinMode( motor1_ena , OUTPUT);
  pinMode( motor1_in1 , OUTPUT);
  pinMode( motor1_in2 , OUTPUT);

  digitalWrite( motor1_in1, LOW);
  digitalWrite( motor1_in2, HIGH );

  Serial.begin(9600);
  pinMode(gas,INPUT);
  pinMode(relay,OUTPUT);

  digitalWrite(relay,HIGH);
  
  delay(1000);  
}
void loop() 
{
 alc=digitalRead(gas);
 //analogWrite( motor1_ena , speed);
 if(alc==HIGH)
 { 
    speed=255;
    analogWrite( motor1_ena , speed);
    
 
    digitalWrite(relay,LOW);
    
    delay(2000);   
                      
 }
 else
 {
  
    for (; speed >70; speed--) {
    analogWrite(motor1_ena, speed); 
    delay(10);
  }
    digitalWrite(relay,HIGH);
  
  
  delay(1000);
  
 }
}