// Checkout my channel https://youtube.com/c/HKBHD to view more cool videos and projects

#include <SoftwareSerial.h>
SoftwareSerial Direction(4,5); // (RX,TX)

#define SPEED 90 // Maximum value is 255

const int lb = 8;
const int lf = 9;
const int rb = 12;
const int rf = 13;
const int enA = 10;
const int enB = 11;

int dir=0;
int dirnew=5;

//#define Stop 0
//#define forward 1
//#define backward 2
//#define Left 3
//#define Right 4
 
void setup()
{

 pinMode (lb, OUTPUT);
 pinMode (lf, OUTPUT);
 pinMode (rb, OUTPUT);
 pinMode (rf, OUTPUT);
 pinMode (enA, OUTPUT);
 pinMode (enB, OUTPUT);
 Serial.begin(9600);
 Direction.begin(4800);
}
void loop()
{ 
 if(Direction.available()>0)
 {
  dir=Direction.read();
 }
   
  Serial.println(dir);
 
  if(dirnew != dir)
  {
  if(dir==1)
  {
  forward();
  dirnew=dir;
 }
   else if(dir==2)
  {
  turn_left();
  dirnew=dir;
 }
  else if(dir==3)
  {
  turn_right();
  dirnew=dir;
 }
  else if(dir==4)
  {
  reverse();
  dirnew=dir;
  }
   else
  {
    stop();
    dirnew=dir;
  }
  }
 //dir=dirnew;
  //delay(100);
 } 

void forward()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, SPEED);
 analogWrite(enB, SPEED);
}
void turn_left()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, HIGH);
 digitalWrite(rf, LOW);
 analogWrite(enA, SPEED);
 analogWrite(enB, SPEED);
}
void turn_right()
{
 digitalWrite(lb, HIGH);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, SPEED);
 analogWrite(enB, SPEED);
}
void reverse()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, HIGH);
 digitalWrite(rb, LOW);
 digitalWrite(rf, HIGH);
 analogWrite(enA, SPEED);
 analogWrite(enB, SPEED);
}
void stop()
{
 digitalWrite(lb, LOW);
 digitalWrite(lf, LOW);
 digitalWrite(rb, LOW);
 digitalWrite(rf, LOW);
 analogWrite(enA, LOW);
 analogWrite(enB, LOW);
}
