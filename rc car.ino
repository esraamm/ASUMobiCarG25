/////***** DEFINITIONS *****/////
#include <SoftwareSerial.h>
#define RF 46  //right forward 
#define RB 48 // right backward
#define LF 50 //left forward
#define LB 52 //left backward 

#define TX 0
#define RX 1

char x ; byte de=5,in=6;
int k=255; 
///////*** END OF DEFINITIONS ***///////
SoftwareSerial HC(0,1);

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

/*void right(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, HIGH);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  Serial.println("right");
  }  */
  
void right(){
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);  
  Serial.println("right");
  }

/*void left(){
   digitalWrite(RF, HIGH);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);  
  Serial.println("left");
  }   */
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
  pinMode(de , OUTPUT);
  pinMode(in , OUTPUT);
       //// end of motors pins ////
       Serial.begin(9600);  
 HC.begin(9600);

}

void loop() {

  while (Serial.available()>0){
   
    x = HC.read() ; 
  
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
