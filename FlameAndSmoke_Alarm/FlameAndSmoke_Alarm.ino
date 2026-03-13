#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int smokeSensor = A0;
int flameSensor = A1;
int buzzer = 8;

int smokeValue;
int flameValue;

void setup()
{
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("Fire & Smoke");
  lcd.setCursor(0,1);
  lcd.print("Detector");
  delay(3000);

  lcd.clear();
}

void loop()
{
  smokeValue = analogRead(smokeSensor);
  flameValue = analogRead(flameSensor);

  Serial.print("Smoke: ");
  Serial.print(smokeValue);
  Serial.print("  Flame: ");
  Serial.println(flameValue);

  bool smokeDetected = smokeValue >= 300;
  bool flameDetected = flameValue <= 500;

  lcd.clear();

  if(smokeDetected && flameDetected)
  {
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(0,1);
    lcd.print("FIRE & SMOKE!");
    tone(buzzer,1000);
  }
  else if(smokeDetected)
  {
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(0,1);
    lcd.print("SMOKE DETECTED");
    tone(buzzer,1000);
  }
  else if(flameDetected)
  {
    lcd.setCursor(0,0);
    lcd.print("WARNING!");
    lcd.setCursor(0,1);
    lcd.print("FIRE DETECTED!");
    tone(buzzer,1000);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("NOW IS SAFE");
    lcd.setCursor(0,1);
    lcd.print("No Fire/Smoke");
    noTone(buzzer);
  }

  delay(500);
}