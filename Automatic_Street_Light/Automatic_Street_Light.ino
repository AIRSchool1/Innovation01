#define trigPin 9
#define echoPin 10

int leds[] = {3, 4, 5, 6, 7};
int ledCount = 5;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  Serial.begin(9600);
}

void loop() {

  // ส่งคลื่น Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // อ่านระยะ
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // ถ้าตรวจจับวัตถุใกล้กว่า 50 cm
  if (distance > 0 && distance < 50) {

    // เปิดไฟทั้งหมด
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], HIGH);
    }

    delay(5000); // เปิดไฟ 5 วินาที

    // ปิดไฟทั้งหมด
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(200);
}