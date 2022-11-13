#include "Musical_hc10_BLE_Blutooth.h"

#include "Song_File.h"
#include "Musical_MP3.h"

#include "Musical_Modes.h"

#include "Musical_Song_StandAlone/Musical_Song_StandAlone.h"
#include "BLE_Code.h"

char bleData[BLE_READ_LENGTH] = {0};
char dataToSend[BLE_SEND_LENGTH] = {0};

SoftwareSerial hc10_Blutooth(BLUTOOTH_TX_TO_ARDUINO_RX_PIN, BLUTOOTH_RX_TO_ARDUINO__TX_PIN);

bool blutooth_Setup(){
    hc10_Blutooth.begin(SOFTWARE_SERIAL_SPEED);
    Serial.println("Blutooth hc10 online.");
    return true;
}

bool bl_write(){
    if(hc10_Blutooth.write(dataToSend, BLE_SEND_LENGTH)){
        return true;
    }
    return false;
}

void testBlutooth(){
    while(1){
        read_BleData();
        delay(1000);
    }
}

bool read_BleData(){
    if(!ble_read()){
        return false;
    }
    delay(500);
    
    for (uint8_t i = 0; i < BLE_READ_LENGTH; i++)
    {
        Serial.println((char)(bleData[i]));
    }
    
    if(!checkConnection()){
        return false;
    }
    if(!checkWallCode()){
        return false;
    }

    if(deviceRead()){
        return sendData(getBLEmode(), getBLEdataValue());
    }
    else{ //deviceWrite
        return readData(getBLEmode(), getBLEdataValue());
    }
    return false;
}

bool checkConnection(){
    if(bleData[3] & connectionBit){
        return true;
    }
    return false;
}
bool checkWallCode(){
    if(bleData[0] == cFirst && bleData[1] == cSecond && bleData[2] == cThird){
        return true;
    }
    return false;
}
bool deviceRead(){
    if(bleData[3] & rwbit){
        return true;
    }
    return false;
}
uint8_t getBLEmode(){
    return bleData[3] & modeBit;
}
uint8_t getBLEdataValue(){
    return bleData[4];
}

bool readData(uint8_t mode, uint8_t value){
    switch (mode)
    {
    case mode_up:
        changeMode(static_cast<Available_Mode>((int)value));
        return true;
    case song_up:
        return saS_changeSong(static_cast<Available_Song>((int)value));
    case vol_up:
        if(!value){
            mp3_changeVolume_Down();
        }else{
            mp3_changeVolume_Up();
        }
    default:
        return false;
    }
    return false;
}

bool sendData(uint8_t mode, uint8_t value){
    String output = "";
    switch (mode)
    {
    case mode_up:
    {
        if(value >= NumOfModes || value < 0){
            return false;
        }
        if(value == 0){
            output = getModeName(getCurMode());
        }
        else{
            output = getModeName(static_cast<Available_Mode>((int)value - 1));
        }
        setDataToSend(output.c_str(), output.length());
        return bl_write();
    }
    case song_up:
    {
        if(value >= NumOfSongs || value < 0){
            return false;
        }
        if(value == 0){
            output = getSongName(getCurSong());
        }
        else{
            output = getSongName(static_cast<Available_Song>((int)value));  
        }
        setDataToSend(output.c_str(), output.length());
        return bl_write();
    }
    case inst_up:
    {
        output = getName();
    }
    /*
    case vol_up:

        break;
    case err_up:

        break;
    */
    
    default:
        return false;
        break;
    }
    
    delay(1000);
    setDataToSend(output.c_str(), output.length());
    return bl_write();
}

bool ble_read(){
    if(hc10_Blutooth.available()){
        if(hc10_Blutooth.readBytes(bleData, BLE_READ_LENGTH)){
            return true;
        } 
    }
    return false;
}

void setDataToSend(const char* input, size_t length){
    if(length > BLE_SEND_LENGTH){
        return;
    }
    resetSendData();
    for (size_t i = 0; i < length; i++)
    {
        dataToSend[i] = (uint8_t)(*(input + i));
    }
}

void resetSendData(){
    for (size_t i = 0; i < BLE_SEND_LENGTH; i++)
    {
        dataToSend[i] = 0x00;
    }
}
