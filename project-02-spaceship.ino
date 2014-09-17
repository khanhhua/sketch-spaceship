int switchState = 0;

int prevSwitchState = 0;
int counter = 0;

int warningIndex = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if (switchState != prevSwitchState) {
    // Alternate the red light after each release
    prevSwitchState = switchState;
    
    counter++;
    if (counter%2==0)
      warningIndex = warningIndex==1?2:1;
  }

  if (switchState == LOW) {
    // NOT PRESSED
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    delay(250);
    // TOGGLE the LED
    if (warningIndex==1){
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    } else {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
    delay(250);
  } 
}


