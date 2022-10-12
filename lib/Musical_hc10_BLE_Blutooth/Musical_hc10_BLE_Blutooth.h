#ifndef BLUTOOTH_COM_H
#define BLUTOOTH_COM_H

#include <Arduino.h>
#include <SoftwareSerial.h>

bool blutooth_Setup();
String bl_read();
bool bl_write(String input);

String readData(String keyWord);
bool writeData(String data);

bool isDataNull(String data);
#endif