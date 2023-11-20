
int potValue = 0;
int newSwitch = 25;

int randomGuy = 0;
int ledPinArray[4] = { 32, 31, 30, 29 };
int extraLed = 2;
int buttonPin = 33;
int buttonPin2 = 34;
int toggle = 35;
int buttonPin3 = 36;
int buttonPin4 = 39;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPinArray[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  pinMode(toggle, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(extraLed, OUTPUT);
}

void loop() {
  potValue = analogRead(A13);
 
  delay(100);
  if (digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinArray[i], HIGH);
      
    }
    delay(1000);
    
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinArray[i], LOW);
      
    }
    delay(1000);

  } else if (digitalRead(buttonPin2) == HIGH and digitalRead(toggle) == HIGH and digitalRead(newSwitch) == LOW) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPinArray[i], HIGH);
      delay(potValue);
      digitalWrite(ledPinArray[i], LOW);
      delay(potValue);
    }

  } else if (digitalRead(buttonPin2) == HIGH and digitalRead(toggle) == LOW and digitalRead(newSwitch) == HIGH) {
    for (int i = 3; i > -1; i--) {
      digitalWrite(ledPinArray[i], HIGH);
      delay(potValue);
      digitalWrite(ledPinArray[i], LOW);
    }
  }

else if (digitalRead(buttonPin4) == HIGH) {
  randomGuy = random(29, 33);
  digitalWrite(randomGuy, HIGH);
  delay(potValue);
  digitalWrite(randomGuy, LOW);
  delay(potValue);
}
}