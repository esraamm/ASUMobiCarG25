const int in1=9;
const int in2=8;
const int in3=7;
const int in4=6;
const int ena=10;
const int enb=5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  analogWrite(ena,150);
  analogWrite(enb,100);
  
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 delay(10000);

analogWrite(ena,150);
analogWrite(enb,100);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);

 delay(10000);

 
}

}
