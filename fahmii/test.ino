#include <SoftwareSerial.h>
# define RF 46
# define LF 48
# define RB 50
# define LB 52

SoftwareSerial HC(2,3);
String koko;
void forward(){
 digitalWrite(RF,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(RB,HIGH);
 digitalWrite(LB,HIGH);
 
}

void backward(){
 digitalWrite(RF,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(RB,HIGH);
 digitalWrite(LB,HIGH);
 
}

void right(){
 digitalWrite(RF,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(RB,HIGH);
 digitalWrite(LB,HIGH);
 
}

void left(){
 digitalWrite(RF,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(RB,HIGH);
 digitalWrite(LB,HIGH);
 
}

void stop(){
 digitalWrite(RF,LOW);
 digitalWrite(LF,LOW);
 digitalWrite(RB,LOW);
 digitalWrite(LB,LOW);
 
}

void setup() {
HC.begin (9600);
Serial.begin(9600);
   pinMode(RF,OUTPUT);
   pinMode(LF,OUTPUT);
   pinMode(RB,OUTPUT);
   pinMode(LB,OUTPUT);
   pinMode(10,OUTPUT);
  
}

void loop(){
   Serial.write (HC.read());
while (HC.available()){
  delay(20);
  char c = HC.read();
  koko += c ;
}

if (koko == 'ÿ' )
{
  forward();
 
  }

digitalWrite (10,HIGH);

if (koko.length()>0){
  digitalWrite(RF,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(RB,HIGH);
 digitalWrite(LB,HIGH);
}
delay (1000);
koko = "";
}
 
*/


int izqA=46;
int izqB=48;
int derA=50;
int derB=52;
int vel=255;
int estado='g';
void setup(){
  Serial.begin(9600);
   pinMode(derA,OUTPUT);
   pinMode(derB,OUTPUT);
   pinMode(izqA,OUTPUT);
   pinMode(izqB,OUTPUT);

  
  
  }
void loop(){
  
  if(Serial.available()>0)
  {
    estado= Serial.read();
    }
  if(estado == 'a'){
    
    Serial.println(estado);
    analogWrite(derB,0);
    analogWrite(izqB,0);
    analogWrite(derA,vel);
    analogWrite(izqA,vel);
    
    }
  if(estado=='d'){
    Serial.println(estado);
    analogWrite(derB,vel);
    analogWrite(izqB,0);
    analogWrite(derA,0);
    analogWrite(izqA,vel);

    
    }
  
  if(estado=='c'){
    Serial.println(estado);
    analogWrite(derB,0);
    analogWrite(izqB,0);
    analogWrite(derA,0);
    analogWrite(izqA,0);

    
    }
  if(estado=='b'){
    Serial.println(estado);
    analogWrite(derB,0);
    analogWrite(izqB,vel);
    analogWrite(derA,vel);
    analogWrite(izqA,0);

    
    }
    if(estado=='e'){
    Serial.println(estado);
    analogWrite(derB,vel);
    analogWrite(izqB,vel);
    analogWrite(derA,0);
    analogWrite(izqA,0);

    
    }
   if(estado=='f'){} 
  if(estado=='g'){}
  
  }
  
