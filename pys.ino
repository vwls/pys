/*
  Fletcher Bach for Stupid Hackathon 2017
  "Need to leave an uncomfortable social situation, and fast? PYS has you covered!"
*/

// connect pump and button to these pins
const int pumpPin = 4;
const int buttonPin = 7;
int buttonState = 0;
int lastButtonState = 0;
boolean isPumping = false; //default state: not pumping

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  delay(250);
}

void loop() {
  // read button
  buttonState = digitalRead(buttonPin);

  //checking button state
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {  //button state went from LOW to HIGH
      //set pump variable to true
      isPumping = true;
      //pumpOn = true;
      //pumpOff = false;
    } else {  //button state went from HIGH to LOW
      //set pump variable to false
      isPumping = false;
      //pumpOn = false;
      //pumpOff = true;
    }
    delay(50);
  }
  lastButtonState = buttonState;

  //check if we should run the pump or not
  if (isPumping == true) {
    //COMMENCE THE PISSING PLEASE
    digitalWrite(pumpPin, HIGH);
    Serial.println("COMMENCE THE PISSING");
  } else {
    //STOP THE PISSING PLEASE
    digitalWrite(pumpPin, LOW);
    Serial.println("STOP PISSING");
  }
}
