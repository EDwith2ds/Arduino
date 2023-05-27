#define pwm_out 9
#define pwm_control A0
int adc_value, pwm_value;

void setup()
{
  Serial.begin(9600);
  pinMode(pwm_out, OUTPUT);
}

void loop()
{
  adc_value = analogRead(pwm_control);
  pwm_value = map(adc_value, 0, 4095, 0, 255);
  //map(pwm_value, 0, adc_value, 0, 255);
  Serial.print(adc_value);
  Serial.print("    ");
  Serial.println(pwm_value);
  analogWrite(pwm_out, pwm_value);
}