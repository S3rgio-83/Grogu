#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(7, 8); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define ledPin 13

int bluetoothTx = 10; // bluetooth tx to 10 pin
int bluetoothRx = 11; // bluetooth rx to 11 pin

int IN1 = 14;
int IN2 = 15;
int IN3 = 16;
int IN4 = 17;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void wait_serial_return_ok()
{
  int num = 0;
  char c[16];
  while (1)
  {
    while (Serial.available() > 0)
    {
      c[num] = Serial.read();
      num++;
      if (num >= 15)
        num = 0;
    }
    if (c[num - 2] == 'O' && c[num - 1] == 'K')
     break;
  }
}

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("Iniciando DFPlayer"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("No es posible iniciar:"));
    Serial.println(F("1.Comprueba las conexiones!"));
    Serial.println(F("2.inserta tarjeta SD!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(30);  //Set volume value (0~30).
//  myDFPlayer.volumeUp(); //Volume Up
//  myDFPlayer.volumeDown(); //Volume Down
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL); 
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  myDFPlayer.play(1);
  Serial.println("se despierta grogu");
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  delay(200);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(200);

  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  Serial.begin(9600);
  delay(500);
  Serial.println("CONECTADO"); //p
}

void loop()
{
  if (bluetooth.available() >= 2 ) {
    unsigned int button = bluetooth.read();
    
    if (button == 1) {
      myDFPlayer.play(2);
      Serial.println("suena 0001");
      delay (500);
      Serial.print("G1F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G1F1");
    }

    if (button == 2) {
      myDFPlayer.play(3);
      Serial.println("suena 0002");
      delay (500);
      Serial.print("G2F1\r\n");
     wait_serial_return_ok();
      Serial.println("fin G2F1");
    }

    if (button == 3) {
      myDFPlayer.play(4);
      Serial.println("suena 0003");
      delay (500);
      Serial.print("G3F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G3F1");
    }

    if (button == 4) {
      myDFPlayer.play(5);
      Serial.println("suena 0004");
      delay (500);
      Serial.print("G4F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G4F1");
    }

    if (button == 5) {
      myDFPlayer.play(6);
      Serial.println("suena 0005");
      delay (500);
      Serial.print("G5F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G5F1");
    }

    if (button == 6) {
      myDFPlayer.play(7);
      Serial.println("suena 0006");
      delay (200);
      Serial.print("G6F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G6F1");
    }

    if (button == 7) {
      myDFPlayer.play(8);
      Serial.println("suena 0007");
      delay (200);
      Serial.print("G7F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G7F1");
    }

    if (button == 8) {
      myDFPlayer.play(9);
      Serial.println("suena 0008");
      delay (200);
      Serial.print("G8F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G8F1");
    }

    if (button == 9) {
      myDFPlayer.play(10);
      delay (200);
      Serial.println("suena 0009");
      Serial.print("G9F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G9F1");
    }

    if (button == 10) {
      myDFPlayer.play(11);
      delay (200);
      Serial.println("suena 0010");
      Serial.print("G10F1\r\n");
      wait_serial_return_ok();
      Serial.println("fin G10F1");
    }

    if (button == 11) {
      myDFPlayer.play(12);
      delay (200);
      Serial.println("suena 0011");
      Serial.print("G11F1\r\n");
      wait_serial_return_ok();
    }

    if (button == 12) {
      myDFPlayer.play(13);
      delay (200);
      Serial.println("suena 0012");
      Serial.print("G12F1\r\n");
      wait_serial_return_ok();
    }

  ///////////PARADO/////////
    if (button == 0) {
      //digitalWrite(ledPin, HIGH);
      //myDFPlayer.play(13);
      //Serial.println("melodia parado");
      delay (200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(100);
    }
    
  /////////DELANTATE////// 
    if (button == 14) {
      digitalWrite(ledPin, HIGH);
      myDFPlayer.play(14);
      Serial.println("melodia haciadelante");
      delay (200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(100);
    }

  /////////GIRO DERECHA////
    if (button == 15) {
      myDFPlayer.play(14);
      Serial.println("melodia derecha");
      delay (200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(100);
    }

  /////////GIRO IZQUIERDA////
    if (button == 15) {
      myDFPlayer.play(15);
      Serial.println("melocia izquierda");
      delay (200);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(100);
    }
    
     /////////HACIA ATRAS////// 
    if (button == 16) {
      digitalWrite(ledPin, HIGH);
      myDFPlayer.play(16);
      Serial.println("melodia marcha atras");
      delay (200);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(100);
    }
  }
}
