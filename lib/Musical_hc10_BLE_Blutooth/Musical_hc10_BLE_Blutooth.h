#ifndef BLUTOOTH_COM_H
#define BLUTOOTH_COM_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Data_File.h"

#define BLE_DATA_LENGTH 8
#define BLE_SEND_LENGTH 8
#define DEBUG

bool blutooth_Setup();
//String bl_read();
//bool bl_write(String input);

//String readData();
//bool writeData();

//bool isDataNull(String data);

//void slaveMasterValidation(String data);

bool readData(uint8_t mode, uint8_t value);
bool sendData(uint8_t mode, uint8_t value);
bool read_BleData();
void setDataToSend(const char* input, size_t length);

bool ble_read();

void testBlutooth();

void resetSendData();
//bool writeData_try(String data);
#endif