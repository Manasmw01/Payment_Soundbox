// Author: Nicolas Brondin-Bernard, based on pcbreflux and DFRobot work.

#include <Arduino.h>
#include "DFRobotDFPlayerMini.h"

//HardwareSerial Serial(0);
DFRobotDFPlayerMini myDFPlayer;

int playPausePin = 35;
int nextPin = 27;
int volumeDownPin = 26;
int volumeUpPin = 33;

int volume = 30;
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
  delay(1000);
}

void loop()
{
  if (myDFPlayer.available()) {
    Serial2.println("10000");
    myDFPlayer.playMp3Folder(10000); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(5000);

    Serial2.println("10001");
    myDFPlayer.playMp3Folder(10001); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(5000);

    Serial2.println("10002");
    myDFPlayer.playMp3Folder(10002); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(5000);

    Serial2.println("10003");
    myDFPlayer.playMp3Folder(10003); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
    delay(5000);
  }
}
