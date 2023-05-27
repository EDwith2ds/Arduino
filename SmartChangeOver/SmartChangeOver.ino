// import librarys to be used 
#include <LiquidCrystal.h>

// use snake case always, until necessary
#define GEN_AV A0 // to read the value of the standby gen
#define EEDC_AV A1// to read the value of eed supply
#define gen_start 2 // set to high to start standby gen
#define gen_stop 3 // set to high to stop the standby gen
#define loadxfer 4 // set to high to switch btw eedc and standby gen

/*bool eedc_flag = 0;
bool gen_flag = 0;*/
int rs = 5, e = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
int value = 225, extreme = 1024;// values used for comparison of EEDC_AV 

LiquidCrystal lcd(rs, e, d4, d5, d6, d7); // initializing the lcd pins

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(gen_start, OUTPUT);
  pinMode(gen_stop, OUTPUT);
  pinMode(loadxfer, OUTPUT);

  lcd.begin(16, 2);
  digitalWrite(gen_start, LOW);
  digitalWrite(gen_stop, LOW);
  digitalWrite(loadxfer, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  do{IsOptimal();}
  while(analogRead(EEDC_AV >= value && EEDC_AV < extreme));
  if(analogRead(EEDC_AV < value)){
      SwitchToGenLow();}
    else if(analogRead(EEDC_AV > extreme)){
      SwitchToGenHigh();}
}

void SwitchToGenLow(){// function to switch to standby gen if the eedc voltage is too low 
  delay(10000);// adding a delay to wait and see if the voltage level normalizes
  digitalWrite(gen_start, HIGH);
  delay(500);
  digitalWrite(loadxfer, HIGH);
  lcd.write("low(V): "EEDC_AV);} // to display the value of the eedc voltage

void IsOptimal(){
  digitalWrite(loadxfer, LOW);
  lcd.write("optimal(V): "EEDC_AV);}

void SwitchToGenHigh(){// function to switch to standby gen if the eedc voltage is too high
  delay(10000);// adding a delay to wait and see if the voltage level normalizes
  digitalWrite(gen_start, HIGH);
  delay(500);
  digitalWrite(loadxfer, HIGH);
  lcd.write("high(V): "EEDC_AV);}