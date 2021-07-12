#include <LiquidCrystal.h>
const int rs=11,en=10,d4=9,d5=5,d6=4,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#define trigPin 7
#define echoPin 6
#define D1 8
#define BUZ1 3
float liquid;

int sound=250;
long duration;
float distance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(D1,OUTPUT);
pinMode(BUZ1,OUTPUT);
lcd.setCursor(0,0);
lcd.print("Distance & Time");
lcd.setCursor(0,1);
lcd.print("Measurement");
delay(2000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  //distance=duration*0.034/2;
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
  lcd.clear();
  lcd.print("Time Duration");
  lcd.setCursor(0,1);
  lcd.print(duration);
  lcd.print("ms");
  delay(1000);
  lcd.clear();
  if(distance<=30)
  {
  digitalWrite(D1,HIGH);
  sound=250;
  }
  if(distance>30||distance<=0)
  {
   Serial.println("Out of range");
   noTone(BUZ1);
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm ");
    tone(BUZ1,sound);
  }
   delay(500);
  

}
