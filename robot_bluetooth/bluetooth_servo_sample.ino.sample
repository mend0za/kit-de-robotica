#include <Servo.h>

#include <SoftwareSerial.h>

int elemento;

Servo servo_6;

Servo servo_7;

SoftwareSerial blueToothSerial_1(1,2);

void setupBlueToothConnection_1()
{
  blueToothSerial_1.begin(38400); //Set Bluetooth BaudRate to default baud rate 38400
  blueToothSerial_1.print("\r\n+STWMOD=0\r\n"); //Set the bluetooth work in slave mode
  blueToothSerial_1.print("\r\n+STNA=zum\r\n"); //Set the bluetooth name as" zum"
  blueToothSerial_1.print("\r\n+STPIN=1234\r\n"); //Set SLAVE pincode
  blueToothSerial_1.print("\r\n+STOAUT=1\r\n"); //Auto-connection should be forbidden
  blueToothSerial_1.print("\r\n+STAUTO=0\r\n");
  delay(2000); //This delay is required
  blueToothSerial_1.print("\r\n+INQ=1\r\n"); //Make the slave bluetooth inquirable
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); //This delay is required
  blueToothSerial_1.flush();
}
//

void setup()
{
  Serial.begin(9600);

  elemento = Serial.read();

  servo_6.attach(6);

  servo_7.attach(7);

  Serial.begin(9600);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  setupBlueToothConnection_1();

}


void loop()
{
  char recvChar_1;
  while(1) {
    if(blueToothSerial_1.available()) { //Check if there is any data sent from the remote bluetooth
      recvChar_1 = blueToothSerial_1.read();
      Serial.print(recvChar_1);
    if (elemento == 1) {
      servo_6.write(0);
      delay(20);

    } else {
      servo_6.write(90);
      delay(20);

    }
    if (elemento == 1) {
      servo_7.write(180);
      delay(20);

    } else {
      servo_7.write(90);
      delay(20);

    }
    }
    if(Serial.available()){ //Check if there is any data sent from the local serial terminal
      recvChar_1 = Serial.read();
      blueToothSerial_1.print(recvChar_1);
    }
  }

}
