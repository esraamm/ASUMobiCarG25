int motorA1 = 11;  
int motorA2 = 13;  
int motorB1 = 4;  
int motorB2 = 5;  
int motorC1 = 6;   
int motorC2 = 7;    
int motorD1 = 8;       
int motorD2 = 9;  
int rightSensor = 10;
int middleSensor = 12;  
int leftSensor = 2; 
int enable= 3;   
int Speed =0;
int Reciever =0; 
int trig = A0;
int echo = A1;
long duration, distance;         
void setup()   
{  
 Serial.begin(9600);  
  pinMode(motorA1,OUTPUT);  
  pinMode(motorA2,OUTPUT);  
  pinMode(motorB1,OUTPUT);  
  pinMode(motorB2,OUTPUT);  
  pinMode(motorC1,OUTPUT);  
  pinMode(motorC2,OUTPUT);  
  pinMode(motorD1,OUTPUT);  
  pinMode(motorD2,OUTPUT); 
  pinMode(enable,OUTPUT);   
  pinMode(rightSensor,INPUT);
  pinMode(middleSensor,INPUT) ; 
  pinMode(leftSensor,INPUT);  
   
}  
 void forword()  
{  
  digitalWrite(motorA1,HIGH);  
  digitalWrite(motorA2,LOW);  
  digitalWrite(motorB1,HIGH);  
  digitalWrite(motorB2,LOW);  
  digitalWrite(motorC1,HIGH);  
  digitalWrite(motorC2,LOW);  
  digitalWrite(motorD1,HIGH);  
  digitalWrite(motorD2,LOW);  
  
 }  
  
 
 void turn_left()  
 {  
  digitalWrite(motorA1,HIGH);  
  digitalWrite(motorA2,LOW);  
  digitalWrite(motorB1,HIGH);  
  digitalWrite(motorB2,LOW);  
  digitalWrite(motorC1,LOW);  
  digitalWrite(motorC2,HIGH);  
  digitalWrite(motorD1,LOW);  
  digitalWrite(motorD2,HIGH);  
 }  
  
 void turn_right()  
 {  
   digitalWrite(motorA1,LOW);  
   digitalWrite(motorA2,HIGH);  
   digitalWrite(motorB1,LOW);  
   digitalWrite(motorB2,HIGH);  
   digitalWrite(motorC1,HIGH);  
   digitalWrite(motorC2,LOW);  
   digitalWrite(motorD1,HIGH);  
   digitalWrite(motorD2,LOW);   
 } 
void Stop()  
 {  
   digitalWrite(motorA1,LOW);  
   digitalWrite(motorA2,LOW);  
   digitalWrite(motorB1,LOW);  
   digitalWrite(motorB2,LOW);  
   digitalWrite(motorC1,LOW);  
   digitalWrite(motorC2,LOW);  
   digitalWrite(motorD1,LOW);  
   digitalWrite(motorD2,LOW);
 }
void speedv ( int Speed )
{
  analogWrite (enable,Speed);

 }
 void backword()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  digitalWrite(motorC1,LOW);
  digitalWrite(motorC2,HIGH);
  digitalWrite(motorD1,LOW);
  digitalWrite(motorD2,HIGH);
}



 void loop()  
 {  
   if(Serial.available() > 0)
  {
   Reciever = Serial.read();
    Serial.print( Reciever);
    if (Reciever == '1' )
   {
      speedv (90);
    }
   else if (Reciever == '2' )
    {
     speedv(150);
    }
    else if (Reciever == '3' )
    {
     speedv(180);
    }
   else if (Reciever == '4' )
    {
      speedv(200);
    }
    else if (Reciever == '5' )
    {
     speedv(255);
    }
   else if(Reciever == 'f')
    {
      
      forword();
      
    }
    else if(Reciever == 'b')
    {
      backword();
     
    }
    else if(Reciever == 'l')
    {
       turn_left();
      
    }
     else if(Reciever == 'r')
    {
       turn_right( );
       
    }
    else if(Reciever == 's')
    {
      Stop();
      
    }
     


     else if (Reciever == 'z')
  {
   while ( Reciever == 'z' )
    { 
      
     
    
      int a =digitalRead(rightSensor);
int b =digitalRead(middleSensor);
int c = digitalRead(leftSensor);

  if (a==0&&b==1&&c==0) // forword  

     {
      forword();
      if (a==1&&b==1&&c==1)
      forword();
         if (a==0&&b==0&&c==0)
      forword();
     
     }
 else if (a==1&&b==0&&c==0) // turn right  
     { 
     
      turn_right();
      if (a==1&&b==1&&c==1)
      turn_right();
       if (a==0&&b==0&&c==0)
      turn_right();
   
     }
  else if (a==1&&b==1&&c==0)  // turn right  
     {
      turn_right();
      if (a==1&&b==1&&c==1)
       turn_right();
       if (a==0&&b==0&&c==0)
       turn_right();    
     }
  else if (a==0&&b==0&&c==1) // turn left  
     
      {
      turn_left();
      if (a==1&&b==1&&c==1)
        turn_left();
         if (a==0&&b==0&&c==0)
        turn_left();
            
      }
     
     
  else if (a==0&&b==1&&c==1) // turn left  
     { 
      turn_left();
     
      if (a==1&&b==1&&c==1)
      turn_left();
      
      if (a==0&&b==0&&c==0)
      turn_left();
      
     }
      if(Serial.available() > 0)
    { Reciever = Serial.read();
    Serial.print( Reciever);
     
      
    if ( Reciever == 's' )
    { Stop();
    break;
    }}
    
}
  }

 else if ( Reciever == 'u' )
 {
  //  ultrasonic 

while( Reciever == 'u' )
 { analogWrite(trig , 0);
  delayMicroseconds(2);
  analogWrite(trig , 255);
  delayMicroseconds( 10);
  analogWrite(trig , 0 );
  
  duration = pulseIn(echo,255);
  distance = (duration/2)/29 ;
  Serial.print(distance);
  Serial.println("CM");

  if (distance < 20 )
    turn_right();
  
  if (distance > 20 )
    
    forword();
       if(Serial.available() > 0)
    { Reciever = Serial.read();
    Serial.print( Reciever);
     
      
    if ( Reciever == 's' )
    { Stop();
    break;
    }}

  }
 }
 }
 }
