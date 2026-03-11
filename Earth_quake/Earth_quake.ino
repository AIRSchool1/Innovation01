#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define VIBRATION_SENSOR_PIN 2
#define BUZZER_PIN 8   // Buzzer บน Maker UNO

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Quake Detector");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");

  delay(2000);
  lcd.clear();
}

void loop() {

  int vibration = digitalRead(VIBRATION_SENSOR_PIN);

  if (vibration == HIGH) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("EARTHQUAKE!");
    lcd.setCursor(0, 1);
    lcd.print("Vibration Det.");

    tone(BUZZER_PIN, 1000);   // เสียงเตือน

    delay(5000);

    noTone(BUZZER_PIN);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Quakes");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
  }

}