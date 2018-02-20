void setup() {
  // put your setup code here, to run once:
  pinMode(0 ,OUTPUT);// red
  pinMode(1 ,OUTPUT);// yellow
  pinMode(2 ,OUTPUT);// green

}

void loop() {
  // put your main code here, to run repeatedly:
 
    
  digitalWrite(0 , 1);
  delay(1000);
  digitalWrite(0 , 0);
  
  digitalWrite(1 , 1);
  delay(1000);
  digitalWrite(1 , 0);
  

  digitalWrite( 2 , 1);
  delay(1000);
  digitalWrite(2 , 0);
  
}
