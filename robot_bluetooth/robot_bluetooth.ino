#include <Servo.h>

#include <SoftwareSerial.h>

Servo servoL;
Servo servoR;

#define Stop() { do_servos(90,90); do_servos(90,90); }
#define move_Forward() do_servos(0, 180)
#define move_Backward() do_servos(180, 0)
#define move_Left() do_servos(90, 180)
#define move_Right() do_servos(0, 90)

// BT part

SoftwareSerial blueToothSerial_1(0,1);

const int bt_delay = 2000;

void setupBlueToothConnection_1()
{
  blueToothSerial_1.begin(38400); //Set Bluetooth BaudRate to default baud rate 38400
  blueToothSerial_1.print("\r\n+STWMOD=0\r\n"); //Set the bluetooth work in slave mode
  blueToothSerial_1.print("\r\n+STNA=zum\r\n"); //Set the bluetooth name as" zum"
  blueToothSerial_1.print("\r\n+STPIN=1234\r\n"); //Set SLAVE pincode
  blueToothSerial_1.print("\r\n+STOAUT=1\r\n"); //Auto-connection should be forbidden
  blueToothSerial_1.print("\r\n+STAUTO=0\r\n");
  delay(bt_delay); //This delay is required
  blueToothSerial_1.print("\r\n+INQ=1\r\n"); //Make the slave bluetooth inquirable
  Serial.println("The slave bluetooth is inquirable!");
  delay(bt_delay); //This delay is required
  blueToothSerial_1.flush();
}


void setup()
{
  // setup servo	
  servoL.attach(6);
  servoR.attach(13);


  Stop();

  // setup bluetooth
  Serial.begin(9600);
  Serial.read();
  Serial.begin(9600);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  setupBlueToothConnection_1();


  // wait 1 second
  delay(bt_delay);
}



#define BT_LEFT      -52
#define BT_RIGHT     -46
#define BT_FORWARD   -43
#define BT_BACKWARD  -60
#define BT_STOP      -45

const int time = 300;
const int idle = 40;

void do_servos(int left, int right) {
  servoL.write(left);
  delay(idle);
  servoR.write(right);
  delay(idle);
}



void loop()
{
  char recvChar_1;
  while(1) {
    if(blueToothSerial_1.available()) { //Check if there is any data sent from the remote bluetooth
      recvChar_1 = blueToothSerial_1.read();
      Serial.println(recvChar_1, DEC);
      blueToothSerial_1.flush();
      Serial.flush();
      switch (recvChar_1) {
        case BT_STOP:
          Stop();
          break;
        case BT_LEFT:
          move_Left();
          break;
        case BT_RIGHT:
          move_Right();
          break;
        case BT_FORWARD:
          move_Forward();
          break;
        case BT_BACKWARD:
          move_Backward();
          break;
      }
      
      delay(time);  
      

    }
  }

}



