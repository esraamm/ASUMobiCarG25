// Pin 9 has red LED
// Pin 10 has yellow LED
// Pin 11 has green LED

int redLEDPin = 9;
int yellowLEDPin = 10;
int greenLEDPin = 11;

int redOnTime = 1000;
int redOffTime = 1000;

int yellowOnTime = 1000;
int yellowOffTime = 1000;

int greenOnTime = 1000;
int greenOffTime = 1000;

int i;

void setup() {
  // put your setup code here, to run once:
pinMode (redLEDPin, OUTPUT);
pinMode (yellowLEDPin, OUTPUT);
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

digitalWrite (greenLEDPin, HIGH);
delay (greenOnTime);
digitalWrite (greenLEDPin, LOW);
delay (greenOffTime);

}
