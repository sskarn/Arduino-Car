/*
  2 H-Bridge Motors with 2 Sets of LEDS for Car
  Karnbir Saini, Aishwarya Jha 
  TEJ3M (Grade 11 Sem 2 Summative)
  June 2019
*/

// assigning variables for motors (r1/r2 for right, l3/l4 for left) and LEDs to Arduino pins:
int r1 = 12;
int r2 = 11;
int l3 = 10;
int l4 = 9;
int leftleds = 5;
int rightleds = 2;

// the setup routine runs when the reset button is pressed:
void setup() {                
// initializes the digital pins as outputs.
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT); 
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(leftleds, OUTPUT);
  pinMode(rightleds, OUTPUT);
}
 
void leftOn() {
// turns the left LEDs on by turning on current
  digitalWrite(leftleds, HIGH);
}

void leftOff() {
// turns the left LEDs off by turning off current
  digitalWrite(leftleds, LOW);
}

void rightOn() {
// turns the right LEDs on by turning on current
  digitalWrite(rightleds, HIGH);
}

void rightOff() {
// turns the right LEDs off by turning off current
  digitalWrite(rightleds, LOW);
}

void ledsOff() {
// turns both LEDS off by running the functions described earlier		
  leftOff();
  rightOff();
} 

void ledsOn() {
// turns both LEDS on by running the functions described earlier
  leftOn();
  rightOn();
}

void indBlink() {
// blinks each set of LEDs individually using functions (right turns on, then left turns on with a delay of 1 second between each)
  rightOn();
  leftOff();
  delay(1000);
  leftOn();
  rightOff();
  delay(1000);
}

void allBlink() {
// turns all of the LEDs on and off with a 0.1 second delay between each
  ledsOff();
  delay(100);
  ledsOn();
  delay(100);
}

void blink() {
// runs multiple of the earlier functions described earlier (2 indBlinks and 5 allBlinks)
  indBlink();
  indBlink();
  allBlink();
  allBlink();
  allBlink();
  allBlink();
  allBlink();
}

void forward() {
// moves the car forward by turning both wheels forward
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, LOW);
}

void backward() {
// moves the car backward by turning both wheels backward
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l3, LOW);
  digitalWrite(l4, HIGH);
}

void rightTurn() {
// turns the car right by turning left wheel forward and right wheel backward
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, LOW);
}

void leftTurn() {
// turns the car left by turning right wheel forward and left wheel backward
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, HIGH);
}

void motorsOff() {
// turns both motors off by blocking current from flowing
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
}

/*
the loop routine runs over and over again forever:
order of events:
The car runs blink routine (listed earlier) and then turns LEDs off
The car moves forward for 10 seconds and stops for 1.5 seconds
The car turns left for 10 seconds and stops for 1.5 seconds
The car turns right for 10 seconds and stops for 1.5 seconds
The car moves backwards for 10 seconds with the LEDs on to indicate reversing
The car turns LEDs and motors off and then loops back to the beginning
*/

void loop() {
  blink();
  ledsOff();
  forward();
  delay(10000);
  motorsOff();
  delay(1500);
  leftTurn();
  delay(10000);
  motorsOff();
  delay(1500);
  rightTurn();
  delay(10000);
  motorsOff();
  delay(1500);
  backward();
  ledsOn();
  delay(10000);
  ledsOff();
  motorsOff();
  }
