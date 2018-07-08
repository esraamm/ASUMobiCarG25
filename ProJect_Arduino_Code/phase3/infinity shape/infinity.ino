#include <SoftwareSerial.h>
#define RB 46  //right forward 
#define RF 48 // right backward
#define LF 50 //left forward
#define LB 52 //left backward 
const int ena = 3;
const int enb =10;

void forward(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  Serial.println("forword");
  }

void backward(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  Serial.println("backward");
  }  

  void setup() {
  
        //////MOTORS PINS//// 
  pinMode(RF , OUTPUT);
  pinMode(RB , OUTPUT);
  pinMode(LF , OUTPUT);
  pinMode(LB , OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  }
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ena,150);
  analogWrite(enb,100);
  backward();

 delay(10000);

analogWrite(ena,150);
analogWrite(enb,100);

   forward();  
 delay(10000);

 
}
