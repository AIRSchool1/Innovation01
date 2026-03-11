int flameSensor = 5;   // DO จาก Flame Sensor
int relayPin = 6;      // Relay ควบคุมปั๊มน้ำ
int buzzerPin = 8;     // Buzzer

int flameValue = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(flameSensor, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(relayPin, HIGH);   // ปั๊มปิดตอนเริ่ม
  digitalWrite(buzzerPin, LOW);
}

void loop()
{
  flameValue = digitalRead(flameSensor);

  Serial.print("Flame Sensor: ");
  Serial.println(flameValue);

  // ตรวจพบไฟ
  if(flameValue == LOW)
  {
    Serial.println("FIRE DETECTED!");

    digitalWrite(relayPin, LOW);   // เปิดปั๊มน้ำ
    digitalWrite(buzzerPin, HIGH); // Buzzer ดัง
  }

  // ไม่พบไฟ
  else
  {
    Serial.println("No Fire");

    digitalWrite(relayPin, HIGH);  // ปิดปั๊มน้ำ
    digitalWrite(buzzerPin, LOW);  // ปิด Buzzer
  }

  delay(200);
}