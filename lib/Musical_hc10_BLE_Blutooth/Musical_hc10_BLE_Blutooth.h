#ifndef BLUTOOTH_COM_H
#define BLUTOOTH_COM_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include "Data_File.h"

#define BLE_READ_LENGTH 5
#define BLE_SEND_LENGTH 8
#define DEBUG

bool blutooth_Setup();

bool readData(uint8_t mode, uint8_t value);
bool sendData(uint8_t mode, uint8_t value);
bool read_BleData();
void setDataToSend(const char* input, size_t length);

bool ble_read();

void testBlutooth();

void resetSendData();

bool checkConnection();
bool checkWallCode();
bool deviceRead();
uint8_t getBLEmode();
uint8_t getBLEdataValue();
#endif