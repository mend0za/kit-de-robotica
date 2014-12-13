#include <Servo.h>

Servo servoL;
Servo servoR;
const int SL = 2;
const int SR = 3;

int rs, ls;

const int BLACK=1;
const int WHITE=0;

void setup()
{
  pinMode( SL, INPUT);
  pinMode( SR, INPUT);
  servoR.attach(9);
  servoL.attach(6);
  servoL.write(90);
  servoR.write(90);
  delay(1000);
}

void loop() {
  rs = digitalRead(SR);
  ls = digitalRead(SL);
  
  if (ls == BLACK && rs == BLACK) 
  {
    move_Forward();
  }
  else if (ls == WHITE && rs == BLACK)
  {
    move_Right();
  }
  else if (ls == BLACK && rs == WHITE)
  {
    move_Left();
  }
  else {
    Stop();
  }
  delay(10);
}

void Stop() {
  servoL.write(90);
  delay(10);
  servoR.write(90);
  delay(10);
}

void move_Forward() {
  servoL.write(0);
  delay(10);
  servoR.write(180);
  delay(10);
}

void move_Right() {
  servoL.write(0);
  delay(10);
  servoR.write(90);
  delay(10);
}

void move_Left() {
  servoL.write(90);
  delay(10);
  servoR.write(180);
  delay(10);
}
