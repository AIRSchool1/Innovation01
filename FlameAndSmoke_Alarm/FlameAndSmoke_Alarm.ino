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

  // แสดงค่า Smoke
  lcd.setCursor(0,0);
  lcd.print("S:");
  lcd.print(smokeValue);
  lcd.print("   ");

  // แสดงค่า Flame
  lcd.setCursor(0,1);
  lcd.print("F:");
  lcd.print(flameValue);
  lcd.print("   ");

  // ตรวจจับเหตุจริงเท่านั้น
  if(smokeValue > 500) 
  {
    lcd.setCursor(10,0);
    lcd.print("SMOKE");
    tone(buzzer,1200);
  }

  else if(flameValue < 400)
  {
    lcd.setCursor(10,1);
    lcd.print("FIRE ");
    tone(buzzer,1500);
  }

  else
  {
    noTone(buzzer);
    lcd.setCursor(10,0);
    lcd.print("     ");
    lcd.setCursor(10,1);
    lcd.print("     ");
  }

  delay(500);
}