#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>
#include <SoftwareSerial.h>
#define BT_RX 1
#define BT_TX 0

int sensor0 = A0;
int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;
int sensor5 = A5;
int sensor0_val, sensor1_val, sensor2_val, sensor3_val, sensor4_val, sensor5_val;
SoftwareSerial Bluetooth(BT_RX, BT_TX);

void setup() {
  Serial1.begin(9600);
  Bluetooth.begin(9600);
  delay(300);
}

void loop() {
  sensor0_val = analogRead(sensor0);
  sensor1_val = analogRead(sensor1);
  sensor2_val = analogRead(sensor2);
  sensor3_val = analogRead(sensor3);
  sensor4_val = analogRead(sensor4);
  Serial1.write('H');             // ヘッダの送信
  Serial1.write(highByte(sensor0_val)); // 上位バイトの送信
  Serial1.write(lowByte(sensor0_val));  // 下位バイトの送信
  Serial1.write(highByte(sensor1_val));
  Serial1.write(lowByte(sensor1_val));
  Serial1.write(highByte(sensor2_val));
  Serial1.write(lowByte(sensor2_val));
  Serial1.write(highByte(sensor3_val));
  Serial1.write(lowByte(sensor3_val));
  Serial1.write(highByte(sensor4_val));
  Serial1.write(lowByte(sensor4_val));
  Serial1.println("A0="+String(sensor0_val)+", A1="+String(sensor1_val)+", A2="+String(sensor2_val)+", A3="+String(sensor3_val)+", A4="+String(sensor4_val));
}
