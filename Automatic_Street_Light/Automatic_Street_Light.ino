#define trigPin 9
#define echoPin 10

// Street light LEDs (you can add/remove pins here)
int leds[] = {3, 4, 5, 6, 7};  
int ledCount = 5;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);  // Start OFF
  }

  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance < 50) {
    // Sequential ON-OFF (1 second per LED)
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], HIGH);   // Turn ON current LED
      delay(1000);                   // Keep ON for 1 sec
      digitalWrite(leds[i], LOW);    // Turn OFF before next one
    }
  } else {
    // No object → keep all OFF
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], LOW);
    }
  }

  delay(200);
}