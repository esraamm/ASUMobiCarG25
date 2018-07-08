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


//Motor control pins- 

const int RB = 46 ; //right forward 
const int RF = 48; // right backward
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
      
}

void loop() {
       analogWrite (ena ,motospeed);
       analogWrite (enb ,motospeed);
            
      int S0 = digitalRead(IR0);
      int S1 = digitalRead(IR1);
      int S2 = digitalRead(IR2);
   
      // print the sensor values:

      //Conditions to drive line folower appropriately


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
