int R1 =2;
int Y1 =3;
int G1 = 4;
int P1=5;
int R2=6,Y2=7,G2=8,P2=9;
int Pb1 =10;
int Pb2 =11;

void setup() 
{
  // put your setup code here, to run once:
pinMode(R1,OUTPUT);
pinMode(Y1,OUTPUT);
pinMode(G1,OUTPUT);
pinMode(P1,OUTPUT);
pinMode(R2,OUTPUT);
pinMode(Y2,OUTPUT);
pinMode(G2,OUTPUT);
pinMode(P2,OUTPUT);
pinMode(Pb1,INPUT_PULLUP);
pinMode(Pb2,INPUT_PULLUP);
//INITIALIATIONS
digitalWrite(R1,LOW);
digitalWrite(Y1,LOW);
digitalWrite(G1,LOW);
digitalWrite(P1,LOW);
}

void loop() 
{
  // put your main code here, to run repeatedly:
Traffic_flow();
}

void Traffic_flow()
{
  LANE1_PASS();
  delay(3000);
  LANES_READY();
  delay(2000);
  Pass_Pedestrain();
  LANE2_PASS();
  delay(3000);
  LANES_READY();
  delay(2000);
  Pass_Pedestrain();
}

void LANE1_PASS()
{
  digitalWrite(R1,LOW);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,HIGH);
  digitalWrite(P1,LOW);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(P2,LOW);
  
}

void LANES_READY()
{
  digitalWrite(R1,LOW);
  digitalWrite(Y1,HIGH);
  digitalWrite(G1,LOW);
  digitalWrite(P1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,HIGH);
  digitalWrite(G2,LOW);
  digitalWrite(P2,LOW);
}

void LANE2_PASS()
{
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(P1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,HIGH);
  digitalWrite(P2,LOW);
}

void Pass_Pedestrain()
{
  bool PB1State, PB2State;
  PB1State = digitalRead(Pb1);
  PB2State = digitalRead(Pb2);
 if(PB1State == LOW||PB2State ==LOW)
   {
   //LANES_READY();
   digitalWrite(P2,HIGH);
   digitalWrite(P1,HIGH);
   delay(400);
   digitalWrite(P2,LOW);
   digitalWrite(P1,LOW);
   delay(400);
   digitalWrite(P2,HIGH);
   digitalWrite(P1,HIGH);
   delay(400);
   digitalWrite(P2,LOW);
   digitalWrite(P1,LOW);
   delay(400);
    
   PEDESTRAIN();
   delay(3000);
   }
  
}

void PEDESTRAIN()
{  
  digitalWrite(R1,HIGH);
  digitalWrite(Y1,LOW);
  digitalWrite(G1,LOW);
  digitalWrite(P1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(Y2,LOW);
  digitalWrite(G2,LOW);
  digitalWrite(P2,HIGH);
}
