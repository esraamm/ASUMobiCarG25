int x = 1 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(4 , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(x%2==0)
  digitalWrite(4 , 1);
  else
  digitalWrite(4 , 0);
  x++,
  
  delay(1000);
}
