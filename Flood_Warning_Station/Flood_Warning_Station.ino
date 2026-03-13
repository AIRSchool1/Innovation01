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

  // ไม่มีน้ำ
  if (waterValue < 150) {

    digitalWrite(ledLow, LOW);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledHigh, LOW);

    noTone(buzzer);
  }

  // น้ำต่ำ
  else if (waterValue >= 150 && waterValue < 400) {

    digitalWrite(ledLow, HIGH);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledHigh, LOW);

    noTone(buzzer);
  }

  // น้ำระดับกลาง
  else if (waterValue >= 400 && waterValue < 700) {

    digitalWrite(ledLow, LOW);
    digitalWrite(ledMedium, HIGH);
    digitalWrite(ledHigh, LOW);

    tone(buzzer, 1000);  // Buzzer ดัง
  }

  // น้ำสูง
  else {

    digitalWrite(ledLow, LOW);
    digitalWrite(ledMedium, LOW);
    digitalWrite(ledHigh, HIGH);

    tone(buzzer, 1500);  // ดังถี่ขึ้น
  }

  delay(300);
}