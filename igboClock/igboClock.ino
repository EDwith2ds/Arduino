#include "RtcDS1302.h"
#include "ThreeWire.h"

ThreeWire mywire(2, 3, 4);
RtDS1302<ThreeWire> rtc(mywire);

void setup()
{
  // put your setup code here, to run once:
rtc.Begin();
Serial.begin()
}

void loop() {
  // put your main code here, to run repeatedly:

}
