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
  void right(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  Serial.println("right");
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
    
 analogWrite(ena,100);
 analogWrite(enb,100);

    forward();
    delay(2000);
 
  analogWrite(ena,100);
  analogWrite(enb,100);
  
    right();
    delay(600);
    
  analogWrite(ena,100);
  analogWrite(enb,100);
  
   forward(); 
  delay(2000);
   
  analogWrite(ena,100);
  analogWrite(enb,100);

      right();
    delay(600);
    
    analogWrite(ena,100);
    analogWrite(enb,100);

       forward(); 
       delay(2000);
    
    analogWrite(ena,100);
    analogWrite(enb,100);

        right();
       delay(600);
    
    analogWrite(ena,100);
    analogWrite(enb,100);

       forward(); 
       delay(2000);
    
    analogWrite(ena,100);
    analogWrite(enb,100);

          right();
        delay(600);

  }