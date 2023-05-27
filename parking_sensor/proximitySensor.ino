int buzzerPin = 12;
int trigPin = 7;
int echoPin = 5;

float distance, duration;

void setup() {
  pinMode(buzzerPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0347 / 2);
  nhw
  Serial.println(distance);

  if (distance <= 5.0) {
    digitalWrite(buzzerPin, HIGH);
  } else if (distance > 5.0 && distance <= 10.0) {
      digitalWrite(buzzerPin, HIGH);
      delay(30);
      digitalWrite(buzzerPin, LOW);
      delay(30);
    }
  else if (distance > 10.0 && distance <= 15.0) {
    digitalWrite(buzzerPin, HIGH);
    delay(60);
    digitalWrite(buzzerPin, LOW);
    delay(60);
  } 
  else if (distance > 15.0 && distance <= 25.0) {
    digitalWrite(buzzerPin, HIGH);
    delay(90);
    digitalWrite(buzzerPin, LOW);
    delay(90);
  } 
  else if (distance > 25.0) {
    digitalWrite(buzzerPin, LOW);
  } 
}