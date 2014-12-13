#include <Servo.h>

Servo servoL;
Servo servoR;
const int SL = 2;
const int SR = 3;

int rs, ls;

const int BLACK=1;
const int WHITE=0;
const int LEFT=0;
const int RIGHT=1;

int direction = LEFT;

void setup()
{
  pinMode( SL, INPUT);
  pinMode( SR, INPUT);
  servoR.attach(9);
  servoL.attach(6);
  servoL.write(90);
  servoR.write(90);
  delay(2000);
}

void loop() {
  rs = digitalRead(SR);
  ls = digitalRead(SL);


  
  if (ls == WHITE && rs == WHITE) 
  {
    move_Forward();
  }
  else if (ls == BLACK && rs == BLACK)
  {
    move_Backward(direction);
    direction = (direction == LEFT) ? RIGHT : LEFT;
  }
  else if (ls == WHITE && rs == BLACK)
  {
    move_Left(1000);
  }
  else if (ls == BLACK && rs == WHITE)
  {
    move_Right(1000);
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

void move_Backward(int direction) {
  servoL.write(180);
  delay(300);
  servoR.write(0);
  delay(300);  
  
  if (direction == LEFT) 
    move_Left(1000);
  else
    move_Right(1000);  
  
}

void move_Right(int time) {
  servoL.write(90);
  delay(time);
  servoR.write(0);
  delay(time);
}

void move_Left(int time) {
  servoL.write(180);
  delay(time);
  servoR.write(90);
  delay(time);
}
