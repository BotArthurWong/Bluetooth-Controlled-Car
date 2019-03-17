#include<SoftwareSerial.h>
#define TIMEOUT 100

SoftwareSerial BTSerial(1, 0); //RX,TX
int state = 0; //for incoming serial data
long startTime = millis();
int enA = 10;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enB = 5;
int LedDepan = 13;
int LedKiri = 12;
int LedKanan = 11;

void setup()
{
  pinMode (enA, OUTPUT) ;
  pinMode (in1, OUTPUT) ;
  pinMode (in2, OUTPUT) ;
  pinMode (in3, OUTPUT) ;
  pinMode (in4, OUTPUT) ;
  pinMode (enB, OUTPUT) ;
  BTSerial.begin(9600);
}

void loop()
{
  if (BTSerial.available () > 0 )   //condition when you receive data
  {
    state = BTSerial.read();       //state = read incoming data

    startTime = millis();

    if (state == 'w')
    {
      forward();
    }
    else if (state == 's')
    {
      reverse();

    }
    else if (state == 'd')
    {
      left();
    }
    else if (state == 'a')
    {
      right();
    }
  }

  else if (millis() - startTime >= TIMEOUT) //if nothing data receive
  {
    stop();
  }
}
void forward()
{
  //forward the car
  analogWrite(enA, 250)  ;
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW) ;

  analogWrite(enB, 250);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void reverse ()
{
  //reverse the car
  analogWrite(enA, 250)  ;
  digitalWrite(in1, HIGH) ;
  digitalWrite(in2, LOW);

  analogWrite(enB, 250)  ;
  digitalWrite(in3, HIGH) ;
  digitalWrite(in4, LOW);

  digitalWrite(LedKiri, HIGH);
  digitalWrite(LedKanan, HIGH);
}
void left()
{
  analogWrite(enA, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);

  digitalWrite(enB, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void right()
{
  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(enB, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stop()
{
  //stop the car moving
  analogWrite(enA, 0)   ;
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH) ;

  analogWrite(enB, 0)   ;
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH) ;

  digitalWrite(LedDepan, LOW);
  digitalWrite(LedKanan, LOW);
  digitalWrite(LedKiri, LOW);
}

