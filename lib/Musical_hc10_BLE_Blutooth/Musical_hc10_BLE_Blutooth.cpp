#include "Musical_hc10_BLE_Blutooth.h"

#include "Song_File.h"
#include "Musical_MP3.h"

#include "Musical_Modes.h"

#include "Musical_Song_StandAlone/Musical_Song_StandAlone.h"
#include "BLE_Code.h"

uint8_t bleData[BLE_DATA_LENGTH] = {0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00};
uint8_t dataToSend[BLE_SEND_LENGTH] = {0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00};

SoftwareSerial hc10_Blutooth(BLUTOOTH_TX_TO_ARDUINO_RX_PIN, BLUTOOTH_RX_TO_ARDUINO__TX_PIN);

bool blutooth_Setup(){
    hc10_Blutooth.begin(SOFTWARE_SERIAL_SPEED);
    Serial.println("Blutooth hc10 online.");
    return true;
}

bool bl_write(){
    //int sent = hc10_Blutooth.write(input.c_str());
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
    
    for (uint8_t i = 0; i < 8; i++)
    {
        Serial.println((char)(bleData[i]));
    }
    

    if(bleData[3] == noConnection){
        return false;
    }
    if(bleData[0] != cFirst || bleData[1] != cSecond || bleData[2] != cThird){
        return false;
    }
    
    uint8_t value = (bleData[6] << 4) | bleData[7];
    
    if(bleData[4] == ble_Read){
        return sendData(bleData[5], value);
    }else if(bleData[4] == ble_Write){
        return readData(bleData[5], value);
    }
    return false;
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
    if(hc10_Blutooth.available()){
        if(!hc10_Blutooth.readBytes(bleData, BLE_DATA_LENGTH)){
            return false;
        } 
    }

    switch (mode)
    {
    case mode_up:
    {
        if(value >= NumOfModes || value < 0){
            return false;
        }else if(value == 0){
            String output = getModeName(getCurMode());
            setDataToSend(output.c_str(), output.length());
            return bl_write();
        }
        else{
            String output = getModeName(static_cast<Available_Mode>((int)value));
            setDataToSend(output.c_str(), output.length());
            return bl_write();
        }
    }
    case song_up:
    {
        if(value == 0){
            String output = getSongName(getCurSong());
            setDataToSend(output.c_str(), output.length());
            return bl_write();
        }
        else{
            String output = getSongName(static_cast<Available_Song>((int)value));
            setDataToSend(output.c_str(), output.length());
            return bl_write();
        }
    }
    case inst_up:
    {
        String output = getName();
        setDataToSend(output.c_str(), output.length());
        return bl_write();
    }
    /*case vol_up:

        break;
    case err_up:

        break;*/
    
    default:
        return false;
        break;
    }
    delay(1000);
    return true;
}

bool ble_read(){
    if(hc10_Blutooth.available()){
        if(hc10_Blutooth.readBytes(bleData, BLE_DATA_LENGTH)){
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
/*
bool writeData_try(String data){
    if(data.length() > 8)
        return false;
    bl_write(data);
    delay(1000);
    return true;
}*/

/*String bl_read(){
    String output = "null";
    if(hc10_Blutooth.available()){
        output = hc10_Blutooth.readString();
    }
    return output;
}*/


/*String readData(){
    //return ble_read();
    return "nul";
    String r = bl_read();
    if(!isDataNull(r)){
        if(r.compareTo(master_WantWrite) == 0){
            bl_write(slave_CanRead);
            delay(500);
            Serial.println("Reading now... Waiting for input...");
            
            bool reading = true;
            while(reading){
                r = bl_read();
                if(!isDataNull(r)){
                    bl_write(slave_GotData);
                    delay(500);
                    Serial.println("End reading...");
                    return r;
                }
            }
        }
    }
    return "null";
}*/

/*bool writeData(String data){
    bl_write(slave_WantWrite);
    delay(1000);
    String input = bl_read();
    if(!isDataNull(input)){
        if(input.compareTo(master_CanRead) == 0){
            Serial.println("Writing Data...");
            slaveMasterValidation(data);
            Serial.println("Finished Writing...");
            return true;
        }
    }
    return false;
}*/

/*bool isDataNull(String data){
    if((data.compareTo("null") != 0) && (data.compareTo("ERROR") != 0)){
        return false;
    }
    return true;
} 

void slaveMasterValidation(String data){
    while(bl_read().compareTo(master_GotData) != 0){
        bl_write(data);
        delay(1000);
    }
}*/