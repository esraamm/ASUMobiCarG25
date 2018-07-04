/////***** DEFINITIONS *****/////
#include <SoftwareSerial.h>
#define RF 46  //right forward 
#define RB 48 // right backward
#define LF 50 //left forward
#define LB 52 //left backward 
char x ; byte de=5,in=6;
int k=255;
///////*** END OF DEFINITIONS ***///////
SoftwareSerial HC(3,2);

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
Serial.write(HC.read());
  if (Serial.available()){
   
    x = Serial.read() ; 
      Serial.print("H");

   if (x=='F'){
      forward();
    }else if(x=='B'){
      backward();
    }else if (x == 'R'){
      right();
    }else if (x=='L'){
      left();
    }else if ( x=='S'){
    stop_motor();
    }
    else if(x=='6'&&k==255){
      analogWrite(de,127.5);
      k=127.5;
    }else if(x=='6'&&k==127.5){
      analogWrite(de,63.75);
      k=63.75;
    }else if(x=='6'&&k==63.75){
      analogWrite(de,31.875);
      k=31.875;
    }else if(x=='7'&&k==31.875){
      analogWrite(in,63.75);
      k=63.75;
    }else if(x=='7'&&k==63.75){
      analogWrite(in,127.5);
      k=127.5;
    }else if(x=='7'&&k==127.5){
      analogWrite(in,255);
      k=255;
    }

  }
}
