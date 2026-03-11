const int sensorPin = A5; // define the sensor pin
const int buzzerPin = 11; // define the buzzer pin

void setup() {
  pinMode(sensorPin, INPUT); // set sensor pin as input
  pinMode(buzzerPin, OUTPUT); // set buzzer pin as output
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // read the sensor value
  
  if (sensorValue == HIGH) { // if vibration is detected
    for (int i = 0; i < 10; i++) { // beep the buzzer 10 times
      digitalWrite(buzzerPin, HIGH); // turn the buzzer on
      delay(100); // wait for 100 milliseconds
      digitalWrite(buzzerPin, LOW); // turn the buzzer off
      delay(100); // wait for 100 milliseconds
    }
    delay(1000); // wait for 1 second before detecting vibration again
  }
}
