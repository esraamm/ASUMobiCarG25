#include <SoftwareSerial.h>
SoftwareSerial BC06(10,11);
int x;

void setup()
{ 
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  BC06.begin(9600);
}

void loop()
{
  {
 if(BC06.available())
  x = BC06.read();
  Serial.println(x);

//}
//if (x == 70) 
//{
  //foward code 
  // right wheel foeward
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  
  // left wheel forward
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
  
  //stop for 2 secs
 
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(2000);

   //backward code
   //Right wheel backward
   digitalWrite(6,LOW);
   digitalWrite(7,HIGH);
   //Left wheel backward
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
   delay(2000);

   //stop for 2 secs
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(2000);
}
