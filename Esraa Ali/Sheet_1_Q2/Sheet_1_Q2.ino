// Pin 9 has red LED
// Pin 10 has yellow LED
// Pin 11 has green LED

int redLEDPin = 4;
int yellowLEDPin = 5;
int blueLEDPin = 6;
int greenLEDPin = 7;

int redOnTime = 1000;
int redOffTime = 1000;

int yellowOnTime = 1000;
int yellowOffTime = 1000;

int blueOnTime = 1000;
int blueOffTime = 1000;

int greenOnTime = 1000;
int greenOffTime = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode (redLEDPin, OUTPUT);
pinMode (yellowLEDPin, OUTPUT);
pinMode (blueLEDPin, OUTPUT);
pinMode (greenLEDPin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  
digitalWrite (redLEDPin, HIGH);
delay (redOnTime);
digitalWrite (redLEDPin, LOW);
delay (redOffTime);

digitalWrite (yellowLEDPin, HIGH);
delay (yellowOnTime);
digitalWrite (yellowLEDPin, LOW);
delay (yellowOffTime);

digitalWrite (blueLEDPin, HIGH);
delay (blueOnTime);
digitalWrite (blueLEDPin, LOW);
delay (blueOffTime);

digitalWrite (greenLEDPin, HIGH);
delay (greenOnTime);
digitalWrite (greenLEDPin, LOW);
delay (greenOffTime);

digitalWrite (blueLEDPin, HIGH);
delay (blueOnTime);
digitalWrite (blueLEDPin, LOW);
delay (blueOffTime);

digitalWrite (yellowLEDPin, HIGH);
delay (yellowOnTime);
digitalWrite (yellowLEDPin, LOW);
delay (yellowOffTime);
}
