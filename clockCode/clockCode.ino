#include "RtcDS1302.h"
#include "ThreeWire.h"
#include "LiquidCrystal.h"

ThreeWire mywire(2, 3, 4); // (IO, SCLK, CE) == (DAT, CLK, RST)
RtcDS1302<ThreeWire> rtc(mywire);
LiquidCrystal lcd(5,6,7,8,9,10);

void setup()
{

  lcd.begin(16, 2);
  rtc.Begin();
  Serial.begin(9600);
  
  lcd.setCursor(0, 0);
  lcd.print("konichiwa");
  delay(100);
  lcd.clear();

  RtcDateTime dt = RtcDateTime(__DATE__,__TIME__);
  rtc.SetDateTime(dt);  
}
void loop()
{
  RtcDateTime now = rtc.GetDateTime();

  //to show what the lcd suppose dey print out
  Serial.print(now.Hour());
  Serial.print(":");
  Serial.print(now.Minute());
  Serial.print(":");
  Serial.println(now.Second());

  lcd.setCursor(0, 0);
  lcd.print("Day: ");
  lcd.print(now.DayOfWeek());
  
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":");
  if(now.Minute() < 10){lcd.print("0");}
  lcd.print(now.Minute());
  lcd.print(":");
  if(now.Second() < 10){lcd.print("0");}
  lcd.print(now.Second());
  delay(1000);
}