#include <RTClib.h>

#include<Wire.h>
#include<LiquidCrystal.h>
#include "RTClib.h"

RTC_DS1307 rtc;
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
char daysofTheWeek[7][12]={"SUN","MON","TUE","WED","THRU","FRI","SAT"};
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("RealTime Clock");
  delay(1000);
  lcd.clear();
  if(!rtc.begin()){
    lcd.print("could'nt found rtc");
    while(1);
  }
  if(!rtc.isrunning()){
    lcd.print('rtc is not running');
  }
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
}
void loop(){
  DateTime now=rtc.now();
  lcd.setCursor(0,1);
  lcd.print("TIME");
  lcd.print(":");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print("");
  lcd.setCursor(0,0);
  lcd.print("DATE");
  lcd.print(":");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
  lcd.print("");
}
