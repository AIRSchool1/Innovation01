int waterSensor = A0;

int ledLow = 3;
int ledMedium = 4;
int ledHigh = 5;

int buzzer = 8;

int waterValue;

void setup() {

  pinMode(ledLow, OUTPUT);
  pinMode(ledMedium, OUTPUT);
  pinMode(ledHigh, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  waterValue = analogRead(waterSensor);

  Serial.print("Water Level: ");
  Serial.println(waterValue);

  // น้ำต่ำ
  if (waterValue < 300) {

    digitalWrite(ledLow, HIGH);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledHigh, LOW);

    noTone(buzzer);
  }

  // น้ำระดับกลาง
  else if (waterValue >= 300 && waterValue < 600) {

    digitalWrite(ledLow, LOW);
    digitalWrite(ledMedium, HIGH);
    digitalWrite(ledHigh, LOW);

    tone(buzzer, 1000);
  }

  // น้ำสูง
  else {

    digitalWrite(ledLow, LOW);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledHigh, HIGH);

    tone(buzzer, 1500);
  }

  delay(500);
}