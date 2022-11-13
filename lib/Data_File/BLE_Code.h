 #ifndef BLE_CODE_H 
 #define BLE_CODE_H 

 enum BLE_Code{
    cFirst = 0xfa,
    cSecond = 0xcc,
    cThird = 0xdf,
    ble_Read = 0x00,
    ble_Write = 0x01,
    connectionBit = 0x80,
    modeBit = 0x3f,
    rwbit = 0x40,
    err_up = 0x00,
    mode_up = 0x01,
    song_up = 0x02,
    inst_up = 0x03,
    vol_up = 0x04
 };

 #endif