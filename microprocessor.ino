#include<SoftwareSerial.h>
SoftwareSerialmySerial(6, 7);
#define m11 5 // left-motor-forward
#define m12 4 // left-motor-backward
#define m21 3 // right-motor-forward
#define m22 2 // right-motor-backward
void forward()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, L
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void right(){
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
}
void Stop()
{
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
}
void setup()
{
mySerial.begin(9600);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);
}
void loop()
{
if (mySerial.available())
{
char ch=(char)(mySerial.read());
if(ch=='W')
{
forward();
}
else if(ch=='D')
{
right();
}
else if(ch=='A')
{
left();
}
else if(ch=='S')
{
backward();
}
else if(ch=='X')
{
Stop();
}
}
}