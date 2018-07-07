const int in1= 9 ;
const int in2 = 8 ;
const int in3 = 7;
const int in4 = 6;
const int ena = 10 ;
const int enb = 5;
char readchar;
String s="";
char r;


int volt=255;

void Forward() {
   analogWrite(ena,volt);
   analogWrite(enb,volt);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }

void Backward()
{
    analogWrite(ena,volt);
   analogWrite(enb,volt);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void Right()
{
  analogWrite(enb,volt);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }

void Left()
{
  analogWrite(ena,volt);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void Stop()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}
const byte MOTOR_A =13;  // Motor 2 Interrupt Pin - INT 1 - Right Motor
//const byte MOTOR_B = 13;  // Motor 1 Interrupt Pin - INT 0 - Left Motor
 
// Constant for steps in disk
const float stepcount = 20.00;  // 20 Slots in disk, change if different
 
// Constant for wheel diameter
const float wheeldiameter = 64.00; // Wheel diameter in millimeters, change if different
 
// Integers for pulse counters
volatile int counter_A = 0;
//volatile int counter_B = 0;


 
// Motor B pulse count ISR
//void ISR_countB()  
//{
 // counter_B++;  // increment Motor B counter value
//}
 
// Function to convert from centimeters to steps

int CMtoSteps(float cm) {
 
  int result;  // Final calculation result
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = (int) f_result/8; // Convert to an integer (note this is NOT rounded)
  
  return result;  // End and return 
 Serial.println("result");
 Serial.println(result);
}
int CMtoSteps2(float cm) {
 
  int result;  // Final calculation result
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step;  // Calculate result as a float
  result = (int) f_result; // Convert to an integer (note this is NOT rounded)
  
  return result;  // End and return 
 Serial.println("result");
 Serial.println(result);
}
// Function to Move Forward
void MoveForward(int steps, int mspeed) 
{
    

      Serial.println("d5lna al fn ");
      Serial.println(steps);

   counter_A = 0;  //  reset counter A to zero
   
   // Go forward until step value is reached
   while (steps > counter_A ) {
       Forward();
   if(digitalRead(13)==HIGH)
  {

  if(digitalRead(13)==LOW)
  {
      counter_A++;
   Serial.println(counter_A);
  }
  if(counter_A>steps)
  {
    
    break;
    }
    
  }

   
   }
    
  // Stop when done
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  counter_A = 0;  //  reset counter A to zero
 
}
 

// Function to Move in Reverse
void MoveReverse(int steps, int mspeed) 
{
   counter_A = 0;  //  reset counter A to zero
  // counter_B = 0;  //  reset counter B to zero
   
  Backward();
   
   // Go in reverse until step value is reached
   while (steps > counter_A ) {
   
    if (steps > counter_A) {
    analogWrite(ena, mspeed);
    } else {
    analogWrite(ena, 0);
    analogWrite(enb, 0);

    } 
   //if (steps > counter_B) {
   // analogWrite(enb, mspeed);
   //} 
  
    }
    
  // Stop when done
  Stop();
  counter_A = 0;  //  reset counter A to zero
  //counter_B = 0;  //  reset counter B to zero
}
 void MoveRight(int steps, int mspeed) 
{
    Serial.println("d5lna al fn ");
      Serial.println(steps);

   counter_A = 0;  //  reset counter A to zero
         

   // Go forward until step value is reached
   while (steps > counter_A ) {
       analogWrite(enb,volt);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   if(digitalRead(13)==HIGH)
  {

  if(digitalRead(13)==LOW)
  {
      counter_A++;
   Serial.println(counter_A);
  }
  if(counter_A>steps)
  {
    
    break;
    }
    
  }

   
   }
    
  // Stop when done
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  counter_A = 0;  //  reset counter A to zero
 

   
}
int distoint=0;
  int dis=0;
  String distance;

void setup()
{
Serial.begin(9600);
pinMode(in1, OUTPUT);//left side 
pinMode(in2, OUTPUT);//left 
pinMode(in3, OUTPUT);//right 
pinMode(in4, OUTPUT);//right 
pinMode(ena, OUTPUT);//enable a  left
pinMode(enb, OUTPUT);//enable b   right
pinMode(MOTOR_A, INPUT_PULLUP);//enable b   right


pinMode(13,INPUT);


}
void loop()
{
if(Serial.available()>0)
{
readchar=Serial.read();

if(readchar=='B')
 Backward();
  

if(readchar=='F')
  Forward();

 
  if(readchar=='R')
      Right();
   
  if(readchar=='L')
    Left();

  
if(readchar=='S')
  Stop();
  
/*if (readchar=='a')
  
  {
    delay(10000);
    float m = Serial.read();//angle
    delay(2000);
    float r=Serial.read();//raduis
//(m/360)*(2*3.14*r)
  MoveLeft(CMtoSteps(((m/360)*(2*3.14*r))), 255);
     
   
  }
  */
    
  s=" ";
 }

//===================================================================================
  if (readchar=='R')
{
  //infinty loop 

   analogWrite(ena,200);
 analogWrite(enb,80);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 delay(4000);

 analogWrite(ena,70);
 analogWrite(enb,220);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 delay(4400);

  analogWrite(ena,90);
 analogWrite(enb,220);
 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,LOW);
 delay(25000);

 //rectangle 
 analogWrite(ena,100);
  analogWrite(enb,100);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(2000);
  
  analogWrite(ena,100);
  analogWrite(enb,100);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(600);

  analogWrite(ena,100);
  analogWrite(enb,100);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(2000);
  
  analogWrite(ena,100);
  analogWrite(enb,100);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(600);

  analogWrite(ena,100);
  analogWrite(enb,100);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  delay(2000);
   analogWrite(ena,100);
}
