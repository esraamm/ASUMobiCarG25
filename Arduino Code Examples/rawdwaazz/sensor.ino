int sensorpin=A1;
int ledpin=8;
float x,z;
void setup() {
pinMode(ledpin,OUTPUT);
}

void loop() {
 x=analogRead(sensorpin);
 z=(100*5*z)/(1023);
 if (z>30.0)
 {digitalWrite(ledpin,HIGH);}
 else
 {digitalWrite(ledpin,LOW);}

}
