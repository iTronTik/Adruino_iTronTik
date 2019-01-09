
// iTronTik
// Code for Switch button using Arduino.
// Goal: When the push button is pressed, the LED should glow and maintained till the button is pressed again.

#define LED 13 // LED connection to digital pin 13
#define buttonPin 2   // the pushbutton pin

// variables will change:
int buttonState = LOW;         // variable for reading the pushbutton status
int TempStateVar = LOW;      // Internal temporory state variable
int prev_buttonState = LOW;

void setup() {
  // initialize the LED pin as an input:
  pinMode(LED,  OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && prev_buttonState == LOW ) { //if button is pressed freshly. You can also add the time for which it must be pressed.
    if (TempStateVar == HIGH) { //if the internal state variable is high, pull it down to the low and vice-versa.
      TempStateVar = LOW;
    }
    else {
      TempStateVar = HIGH;
    }
    digitalWrite(LED, TempStateVar); // write corresponding state value to LED
  }
  prev_buttonState = buttonState;
}
