// Fire Detection + Water Pump (Maker UNO)

int flameSensor = 5;   // Flame Sensor DO
int relayPin = 6;      // Relay ควบคุมปั๊ม
int buzzerPin = 8;     // Buzzer บน Maker UNO

int flameValue = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(flameSensor, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, HIGH);   // ปิดปั๊มตอนเริ่ม
  digitalWrite(buzzerPin, LOW);   // ปิดเสียง
}

void loop()
{
  flameValue = digitalRead(flameSensor);

  Serial.print("Flame Sensor: ");
  Serial.println(flameValue);

  // ตรวจพบไฟ
  if(flameValue == LOW)
  {
    Serial.println("🔥 FIRE DETECTED");

    digitalWrite(relayPin, LOW);   // เปิดปั๊มน้ำ
    tone(buzzerPin, 1000);         // Buzzer บน Maker UNO ดัง
  }

  // ไม่พบไฟ
  else
  {
    Serial.println("✅ No Fire");

    digitalWrite(relayPin, HIGH);  // ปิดปั๊ม
    noTone(buzzerPin);             // ปิดเสียง
  }

  delay(200);
}