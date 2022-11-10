 #ifndef BLE_CODE_H 
 #define BLE_CODE_H 

 enum BLE_Code{
    cFirst = 0xfa,
    cSecond = 0xcc,
    cThird = 0xdf,
    ble_Read = 0x00,
    ble_Write = 0x01,
    noConnection = 0xff,
    mode_up = 0x10,
    song_up = 0x11,
    inst_up = 0x12,
    vol_up = 0x13,
    err_up = 0x14
 };

 #endif