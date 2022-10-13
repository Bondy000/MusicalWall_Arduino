#include "Musical_hc10_BLE_Blutooth.h"
#include "Data_File.h"

SoftwareSerial hc10_Blutooth(BLUTOOTH_TX_TO_ARDUINO_RX_PIN, BLUTOOTH_RX_TO_ARDUINO__TX_PIN);

char* cmd;

bool wantToRead = false;

bool blutooth_Setup(){
    hc10_Blutooth.begin(SOFTWARE_SERIAL_SPEED);
    Serial.println("Blutooth hc10 online.");
    return true;
}

bool bl_write(String input){
    int sent = hc10_Blutooth.write(input.c_str());
    if(sent > 0){
        return true;
    }
    return false;
}

String bl_read(){
    String output = "null";
    if(hc10_Blutooth.available()){
        output = hc10_Blutooth.readString();
    }
    return output;
}


String readData(){
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
}

bool writeData(String data){
    bl_write(slave_WantWrite);
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
}

bool isDataNull(String data){
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
}

void testBlutooth(){
    bool test = true;
    while(1){
        if(test){
            String r =readData();
            if(!isDataNull(r)){
                Serial.println(r);
                if(r.compareTo("Hello World") == 0){
                    test = false;
                }
            }
        }else{
            if(writeData("Goodbye Life")){
                test = true;
            }
        }
    }
}