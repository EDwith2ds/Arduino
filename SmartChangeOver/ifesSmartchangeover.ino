#include <LiquidCrystal.h>

#define GEN_AV A0
#define EEDC_AV A1
#define Gen_Start 2
#define Gen_Stop 3
#define Load_Xfer 4

bool eedc_flag = 0;
bool gen_flag = 0;
int rs = 5, e = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Gen_Start, OUTPUT);
  pinMode(Gen_Stop, OUTPUT);
  pinMode(Load_Xfer, OUTPUT);

  lcd.begin(16, 2);
  digitalWrite(Gen_Start, LOW);
  digitalWrite(Gen_Stop, LOW);
  digitalWrite(Load_Xfer, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  check_sensors();
  if (eedc_flag) {
    digitalWrite(Load_Xfer, HIGH);
    digitalWrite(Gen_Stop, HIGH);
    delay(1000);
  }
  else {
    if (!gen_flag) {
      digitalWrite(Load_Xfer, LOW);
      digitalWrite(Gen_Start, HIGH);
      delay(1000);
    }
  }

}

void check_sensors() {
  float eedc_volt = map(analogRead(EEDC_AV), 512, 1023, 0, 1);
  if (eedc_volt) {
    eedc_flag = 1;
  }
  else {
    eedc_flag = 0;
  }
  float gen_volt = map(analogRead(GEN_AV), 0, 1023, 0, 1);
  if (gen_volt) {
    gen_flag = 1;
  }
  else {
    gen_flag = 0;
  }
}