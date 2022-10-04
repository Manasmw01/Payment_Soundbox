// Author: Nicolas Brondin-Bernard, based on pcbreflux and DFRobot work.

#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

//HardwareSerial Serial(0);
DFRobotDFPlayerMini myDFPlayer;

int playPausePin = 35;
int nextPin = 27;
int volumeDownPin = 26;
int volumeUpPin = 33;

int volume = 1;
int musicMode = 1; //1=night,2=day
int songNumber = 1;
int songsCount = 1;
bool isPlaying = true;
bool isNextPressed = false;
unsigned long nextPressedTime;

void printDetail(uint8_t type, int value);
void checkButtons();

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Online Payment");
  lcd.setCursor(3, 1);
  lcd.print("Soundbox");
  pinMode(playPausePin, INPUT);
  pinMode(nextPin, INPUT);
  pinMode(volumeDownPin, INPUT);
  pinMode(volumeUpPin, INPUT);
  digitalWrite(playPausePin, LOW);
  digitalWrite(nextPin, LOW);
  digitalWrite(volumeDownPin, LOW);
  digitalWrite(volumeUpPin, LOW);

  Serial.begin(9600);  // speed, type, RX, TX
  Serial2.begin(115200);

  Serial2.println();
  Serial2.println(F("DFRobot DFPlayer Mini"));
  Serial2.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  while (!myDFPlayer.begin(Serial)) {
    Serial2.println(F("Unable to begin"));
  }
  Serial2.println(F("DFPlayer Mini online."));

  //  songsCount = myDFPlayer.readFileCountsInFolder(2);
  myDFPlayer.volume(volume);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  delay(500);
}

void loop()
{
  if (myDFPlayer.available()) {
    if (Serial2.available() > 0)
    {
      String mmpstr = Serial2.readStringUntil('\n');
      int mmp = mmpstr.toInt();
      Serial2.println(mmp);
      myDFPlayer.playMp3Folder(mmp); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    }
    Serial2.println("Welcome");
    myDFPlayer.playMp3Folder(1010); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(5000);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();
    delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Payment Received");
    lcd.setCursor(0, 1);
    lcd.print("120 Rs");

    Serial2.println("You have received: ");
    myDFPlayer.playMp3Folder(1007); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(1000);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();

    Serial2.println("0001");
    myDFPlayer.playMp3Folder(0001); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(700);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();

    Serial2.println("100");
    myDFPlayer.playMp3Folder(100); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(700);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();

    Serial2.println("And");
    myDFPlayer.playMp3Folder(1012); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(700);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();

    Serial2.println("20");
    myDFPlayer.playMp3Folder(20); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(2000);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();

    //    Serial2.println("5");
    //    myDFPlayer.playMp3Folder(0005); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //        delay(3000);
    Serial2.println("Rupees");
    myDFPlayer.playMp3Folder(1011); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(2000);
    //    delay(15000);
    Serial2.println(myDFPlayer.readType());
    Serial2.println();
    //        Serial2.println("0007");
    //        myDFPlayer.playMp3Folder(0007); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //        delay(1500);
    //
    //    Serial2.println("0008");
    //    myDFPlayer.playMp3Folder(1001); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0009");
    //    myDFPlayer.playMp3Folder(1002); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0010");
    //    myDFPlayer.playMp3Folder(0010); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0011");
    //    myDFPlayer.playMp3Folder(0011); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0012");
    //    myDFPlayer.playMp3Folder(0012); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0013");
    //    myDFPlayer.playMp3Folder(0013); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0014");
    //    myDFPlayer.playMp3Folder(0014); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0015");
    //    myDFPlayer.playMp3Folder(0015); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0016");
    //    myDFPlayer.playMp3Folder(0016); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //    Serial2.println("0017");
    //    myDFPlayer.playMp3Folder(0017); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0018");
    //    myDFPlayer.playMp3Folder(1003); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0019");
    //    myDFPlayer.playMp3Folder(1004); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0020");
    //    myDFPlayer.playMp3Folder(0020); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0030");
    //    myDFPlayer.playMp3Folder(0030); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0040");
    //    myDFPlayer.playMp3Folder(0040); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0050");
    //    myDFPlayer.playMp3Folder(0050); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0060");
    //    myDFPlayer.playMp3Folder(0060); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0070");
    //    myDFPlayer.playMp3Folder(0070); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0080");
    //    myDFPlayer.playMp3Folder(1005); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0090");
    //    myDFPlayer.playMp3Folder(1006); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("0100");
    //    myDFPlayer.playMp3Folder(0100); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
    //
    //    Serial2.println("1000");
    //    myDFPlayer.playMp3Folder(1000); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    //    delay(1500);
  }
}
