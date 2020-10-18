#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int MQ_7_LOW=3;
int GREEN_LED=5;
int YELLOW_LED=4;

void setup() {
  // put your setup code here, to run once:
pinMode(MQ_7_LOW, INPUT_PULLUP);
pinMode(GREEN_LED, OUTPUT);
pinMode(YELLOW_LED, OUTPUT);
lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("SISTEM PENDETEKSI");
lcd.setCursor(0,1);
lcd.print("ALKOHOL");
lcd.setCursor(0,2);
lcd.print("TELEKOMUNIKASI PNJ");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
int MQ_7_LOW_READ = digitalRead(MQ_7_LOW);
if (MQ_7_LOW_READ == LOW)
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL DETECTED");
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  delay(20);
}
else
{
  lcd.clear();
  lcd.setCursor(0, 3);
  lcd.print("ALCOHOL NOT DETECTED");
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(20);
  }
}
