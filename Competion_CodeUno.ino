int sensor1= 4; 
int sensor2=2;
int Sharp1 = 6;
int Sharp2=5; 
int Sharpfront=6; 
int bump=4;
int fan=12;
int redled=11; 
int blueled=3 ;
int sound=10;  
int speed2= 172;
int speed1 = 190 ; 
int M1= 4;
int S1= 5;
int M2= 7;
int S2= 6; 
int reading;  
int reading1; 
int reading2; 
int reading3;
int reading4;
bool fireseen = false; // for counter, moving average for flame
int r1 = 0;
int r2 = 0;
int count = 0;

void setup() 

{
 pinMode(M1, OUTPUT); // select pinmode and define M1 as output 
 pinMode(S1, OUTPUT); // select pinmode and define S1 as output 
 pinMode(M2, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(sensor1, INPUT); 
 pinMode(sensor2, INPUT); 
 pinMode(fan, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(bump, INPUT);
 pinMode(sound, INPUT);  
 pinMode(blueled, OUTPUT);
 Serial.begin(9600);
  bool soundd = false;
while (!soundd)
  {
    soundd = digitalRead(sound);
    digitalWrite(blueled,LOW);
 }
  digitalWrite(blueled,HIGH);
}

void loop()  
{  

  reading = analogRead(Sharp1);
  reading1=analogRead(sensor1); 
  reading2=analogRead(sensor2);
  reading3 = analogRead(Sharpfront);
  reading4 = analogRead(Sharp2);

  
if ((reading1<1000)||(reading2<1000))
{Serial.println(reading1);
Serial.println(reading2);
  fireseen =true;}
else
{fireseen = false;
}
if(fireseen)
{
  flamme();
}
else
{
  if (digitalRead(bump) == LOW)
   {
   digitalWrite(M1, LOW); 
   digitalWrite(M2, LOW); 
   analogWrite(S1,speed1); 
   analogWrite(S2,speed2); 
   delay(300); 
   digitalWrite(M1, HIGH); 
   digitalWrite(M2, LOW); 
   analogWrite(S1,speed1); 
   analogWrite(S2,speed2); 
   delay(300);
   }
  

else if(reading >= 230)// too close go backwards and then right
{
 digitalWrite(M1, LOW); 
 digitalWrite(M2, LOW); 
 analogWrite(S1,speed1); 
 analogWrite(S2,speed2); 
 delay(20);  
 digitalWrite(M1, HIGH); 
 digitalWrite(M2, LOW); 
 analogWrite(S1,speed1); 
 analogWrite(S2,speed2); 
 delay(20);
   
}
 else if (reading<=150 && reading>=130) // too far from wall turn left and then forwards
 {
  digitalWrite(M1, LOW); 
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(30); 
  digitalWrite(M1, HIGH);  
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(10);
 }
 else if (reading<=230 && reading>=200) // right distance from wall go forwards
 {
  digitalWrite(M1, HIGH);  
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(10);
 }
 else if (reading<=115)
 {
  digitalWrite(M1, HIGH);  
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(300);
  digitalWrite(M1, LOW); 
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(30); 
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(80);
  
 }
 else
 {
  digitalWrite(M1, HIGH);    
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(10); 
  } 
}

}
 void flamme  ()
  {
  reading1=analogRead(sensor1); 
  reading2=analogRead(sensor2); 
  digitalWrite(redled, HIGH);
  digitalWrite(fan, HIGH);
 if (reading1<1000 && reading2<1000)
 {
  if (reading1<reading2)
  {
  digitalWrite(M1, LOW); 
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(100); 
  }
  if (reading2<reading1)
  {
    digitalWrite(M1, HIGH); 
  digitalWrite(M2, LOW); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(100); 
  }
  digitalWrite(M1, HIGH); 
  digitalWrite(M2, HIGH); 
  analogWrite(S1,speed1); 
  analogWrite(S2,speed2);
  delay(500); 
  analogWrite(S1,0); 
  analogWrite(S2,0);
  digitalWrite(fan, HIGH);
  delay(7500);
 }
 else if (reading1>1000 && reading2>1000)
 {
   digitalWrite(fan, LOW);
  }
 else if (digitalRead(bump) == LOW)
   {
   digitalWrite(M1, LOW); 
   digitalWrite(M2, LOW); 
   analogWrite(S1,speed1); 
   analogWrite(S2,speed2); 
   delay(300); 
   digitalWrite(M1, LOW); 
   digitalWrite(M2, HIGH); 
   analogWrite(S1,speed1); 
   analogWrite(S2,speed2); 
   delay(300);
   }
   } 
   
  
 
