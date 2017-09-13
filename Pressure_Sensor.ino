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
int sensor0_val, sensor1_val, sensor2_val, sensor3_val, sensor4_val;
SoftwareSerial Bluetooth(BT_RX, BT_TX);
long startTime = 0, lapTime = 0, count = 0;
double R1 = 0.1;
int test = 100;

void setup() {
  Serial1.begin(9600);
//  Bluetooth.begin(9600);
  startTime = micros();
}

void loop() {
  lapTime = micros() - startTime;
  startTime = micros();
  count++;
  sensor0_val = analogRead(sensor0);
  sensor1_val = analogRead(sensor1);
  sensor2_val = analogRead(sensor2);
  sensor3_val = analogRead(sensor3);
  sensor4_val = analogRead(sensor4);
//  Serial1.write(test);
  Serial1.write('H');             // ヘッダの送信
  Serial1.write(lapTime);
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

//  double Vo, Rf, fg;
//  Vo = sensor0_val * 5.0 / 1024;
//  Serial.println("Vo="+String(Vo)+"V");
//  Rf = R1*Vo / (5.0 - Vo);
//  Serial.println("Rf="+String(Rf)+"Ω");
//  fg = (880.79/Rf+47.962)/1000;
//  Serial.println("Load="+String(fg)+"kg");
//  Serial.println("Time="+String(micros())+"count="+count);
//  Serial.println("A0="+String(sensor0_val)+", A1="+String(sensor1_val)+", A2="+String(sensor2_val)+", A3="+String(sensor3_val)+", A4="+String(sensor4_val));
}
