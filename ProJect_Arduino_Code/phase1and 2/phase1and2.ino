 /////***** DEFINITIONS *****/////
#include <SoftwareSerial.h>
#define RB 46  //right forward 
#define RF 48 // right backward
#define LF 50 //left forward
#define LB 52 //left backward 

#define TX 14
#define RX 15
#define trigpin 13
#define echopin 12
 char x ; 
//sensor pins
const int IR0 = 38;
const int IR1 = 40;
const int IR2 = 42;

const int ena = 3;
const int enb =10;
const int W = 0;
const int B = 1; 
const int motospeed = 85; 
int lastState=0;


///////*** END OF DEFINITIONS ***///////


////**** FUNCTIONS ****////
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
  
void right(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  Serial.println("right");
  }

void left(){
  digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);  
  Serial.println("left");
  }

void stop_motor(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW); 
  Serial.println("stop"); 
  }  
  
//////*** END OF FUNCTIONS ***//////

void setup() {
  
        //////MOTORS PINS//// 
  pinMode(RF , OUTPUT);
  pinMode(RB , OUTPUT);
  pinMode(LF , OUTPUT);
  pinMode(LB , OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(trigpin , OUTPUT);
  pinMode(echopin , INPUT);

  pinMode (IR0,INPUT);
  pinMode (IR1,INPUT);
  pinMode (IR2,INPUT);
  
  //// end of motors pins ////
       Serial.begin(9600);  
}

void loop() {

    //ultra
 mmm: digitalWrite (ena ,motospeed);
      digitalWrite (enb ,motospeed);
      
   long duration, distance ;
  digitalWrite (trigpin,LOW);
  delayMicroseconds (1000);
  digitalWrite (trigpin,HIGH);
  delayMicroseconds (1000); 
  digitalWrite (trigpin,LOW); 
  duration = pulseIn(echopin,HIGH);
  distance =  (duration/2)/29.1;
  Serial.println (distance);

 if (distance <= 50){
      stop_motor();
      goto mmm ;
 }
 //bluetooth
else{
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
 }

      //line follower
      int S0 = digitalRead(IR0);
      int S1 = digitalRead(IR1);
      int S2 = digitalRead(IR2);
   
      // print the sensor values:
      
     
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
