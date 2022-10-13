#ifndef BLUTOOTH_COM_H
#define BLUTOOTH_COM_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "hc10_keyword.h"

bool blutooth_Setup();
String bl_read();
bool bl_write(String input);

String readData();
bool writeData(String data);

bool isDataNull(String data);

void slaveMasterValidation(String data);

void testBlutooth();
#endif