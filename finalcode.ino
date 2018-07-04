#define IN1  22             
#define IN2  23              
#define IN3  24             
#define IN4  25             
#define EN1  4             
#define EN2  5 

#define wheelSensor 2
#define stepcount 28
const float wheel_Diameter = 64.5;

void setup() {
  Serial.begin(9600);
 }

char terminal_input[4]; 
char inChar; 
byte index = 0; 

void loop(){
     String str;
     while(Serial.available()){
      str = Serial.readString();
      Serial.println(str);
      char dir = str[0];
      String dis = str.substring(1,str.length());
      float distance = dis.toFloat();
      Serial.println(dir);
      Serial.println(dis);
      Serial.println(distance);

      if(dir == 'f'){
         forward_accurate_movement(CMtoSteps(distance));
        }else if( dir == 'b'){
          backward_accurate_movement(CMtoSteps(distance));
        }
     } 
}

int CMtoSteps(float cm){
  int result;
  float circumference = (wheel_Diameter * 3.14) / 10;
  float cm_step = circumference / stepcount;
  float f_result = cm / cm_step;
  result = (int) f_result; 
  return result; 
}

volatile int slots_counts = 0;
boolean stateNew = LOW;
boolean stateOld = LOW;

void turn_left_90_degree(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      turn_left(150);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  turn_left(0);
}

void forward_accurate_movement(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      forward(200);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0);
  
}

void backward_accurate_movement(int pulses){
  slots_counts = 0;
  while(slots_counts < pulses ){
      backward(80);
      stateNew = digitalRead(wheelSensor);
      if (stateNew != stateOld){
        stateOld = stateNew;
        slots_counts ++;
        Serial.println(slots_counts);
        } 
      } 
  forward(0);
}
int forward(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);  
 }

 int backward(int speeder){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }


 int turn_right(int speeder){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }
 
 int turn_left(int speeder){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    analogWrite(EN1,speeder);
    analogWrite(EN2,speeder);
 }







































































































#include <SoftwareSerial.h>

#define TX 0
#define RX 1

const int W = 0;
const int B = 1; 
const int ena = 3;
const int enb =10;
const int motospeed =85; 
//const int motospeed1 = 100; 
int lastState=0;
//sensor pins
const int IR0 = 38;
const int IR1 = 40;
const int IR2 = 42;
SoftwareSerial HC(RX,TX);
char x ;
//Motor control pins- 

const int RF = 46 ; //right forward 
const int RB = 48; // right backward
const int LF = 50; //left forward
const int LB = 52; //left backward 

void forward(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  //Serial.println("forword");
  }

void backward(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  //0Serial.println("backward");
  }  
void right(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  //Serial.println("right");
  }

  void left(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);  
  //Serial.println("left");
  }
  
 void stop_motor(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW); 
//  Serial.println("stop"); 
  }  


  
void setup() {
      pinMode(RF,OUTPUT);
      pinMode(RB,OUTPUT);
      pinMode(LF,OUTPUT);
      pinMode(LB,OUTPUT);

      pinMode (ena,OUTPUT);
      pinMode (enb,OUTPUT);
      
      pinMode (IR0,INPUT);
      pinMode (IR1,INPUT);
      pinMode (IR2,INPUT);
      
      // initialize the serial communications:
      Serial.begin(9600);
       HC.begin(9600);
}

void loop() {
    while (Serial.available()>0){
   
    x = Serial.read() ; 
  
   Serial.println (" x =  " ) ; Serial.println (x); Serial.println() ;
    
   if (x=='F'){
      forward();
    }
    else if(x=='B'){
      backward();
    } 
    else if (x == 'R'){
      right();
    }
    else if (x=='L'){
      left();
    }
    else if ( x=='S'){
    stop_motor();
    }
  }
       analogWrite (ena ,motospeed);
       analogWrite (enb ,motospeed);
            
      int S0 = digitalRead(IR0);
      int S1 = digitalRead(IR1);
      int S2 = digitalRead(IR2);
   
      // print the sensor values:

      //Conditions to drive line folower appropriately
       /*  if(S1==B)
         {
          forward();
          }*/

         /* Serial.print (" s0 =  " ) ; Serial.print(S0);
           Serial.print (" s1 =  " ) ; Serial.print(S1);
           Serial.print (" s2 =  " ) ; Serial.print(S2);
           Serial.println() ;*/
            
           
         if(S0==W && S1==B && S2==W)
       {
        lastState=1;
       
        forward();
       

       }

          //left cases
         else if(S0==B && S1==W && S2==W)
         {
          lastState=2;

          right();
          
          }
          else if(S0==B && S1==B && S2==W)
         {
          lastState=2;
              
           right();
         

          }
          
          //right cases
         else if(S0==W && S1==W && S2==B)
         {
          lastState=3;
              
         left();
           
          }
          
         else if(S0==W && S1==B && S2==B)
         {
          lastState=3;
               
          left();
          
          }
          /*else if(S0==B && S1==B && S2==W)
          {
            right();
            }//Tutorial Case*/
             else if(S0==B && S1==B && S2==B)
            {
            forward();
          
   
            //stop_motor ();
            }
          else if(S0==W && S1==W && S2==W)
            {
            switch(lastState)
            {
              case 1:
              forward();
               
              break;
              
              case 2:
              right();
       
              break;
              
              case 3:
              left();


              break;
              default:
              stop_motor();
              break;
              }
            }

          
         else 
         { 
         right();
  
          }
     }
