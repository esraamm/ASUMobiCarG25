#include <math.h>
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

int arrayIncludeElement(float d[], char element) {
  int m = sizeof(d);
 for (int i = 0; i <= m; i++) {
      if (d[i] == element) {
          return i;
      }
    }
  return -1;
 }

int int_dist(char array[]){
  int n;
  char a = '0';
  int dis = 0;
  char c[4];
  int d[4];
  for (n = 0; n == 'I'; n++){
    while (Serial.available() > 0){
    c[n] = Serial.read();
    d[n] = c[n] - a;
    dis = dis + d[n]*pow(10,n);
    }
    }
    return dis;
  }
// el code dah law elly dakhel int bas !!

float float_dis(char x){
  int n,i,p = 0;
  float dis = 0;
  char a = '0';
  float d[8];
  char c[8];
  for (n = 0; n == 'F'; n++){
    while (Serial.available() > 0){
      c[n] = Serial.read();
      d[n] = c[n] - a;
      }
      int len = sizeof(d) - 1;
      p = arrayIncludeElement(d, '.');
      for (i = 0; i <= len ; i++){
        if (d[i] == '.'){
        continue;
        }else{
          dis = dis + d[i]*(pow(10,-(p-i)));
          }
      }
    }
    return dis;
  }

  
void setup() {
  // put your setup code here, to run once:
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
      // HC.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char x[4];
    while(Serial.available()){
      for (int i=0 ; i<4 ;i++ ){
      x[i] = Serial.read();
    }
    }
int y = int_dist(x);
Serial.println(y);
}
