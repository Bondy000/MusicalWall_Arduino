#include "hofmanCode.h"

#define DEFUALT_MASK 0x1

uint8_t mask = DEFUALT_MASK;
uint8_t *dec = nullptr;

void setDataPointer(uint8_t* data){
    dec = data;
    mask = DEFUALT_MASK;
}

/*
    0 =     1101        0xd
    1 =     011         0x3 
    2 =     010         0x2
    3 =     00          0x0
    4 =     101         0x5
    5 =     111         0x7
    6 =     1001        0x9
    7 =     11001       0x19
    8 =     100011      0x23
    9 =     10000001    0x81   
    10 =    10000000    0x80
    11 =    100010      0x22
    12 =    NULL
    13 =    10000011    0x83
    14 =    NULL
    15 =    NULL
    16 =    NULL
    17 =    NULL    
    18 =    10000010    0x82
    19 =    110001      0x31
    20 =    110000      0x30
    255 =   100001      0x21
*/
uint8_t decipherHofman(){
    uint8_t d = *dec;
    if(d & mask){   
        /*1*/
        d = addMask(d);
        if(d & mask){ 
            /*11*/
            d = addMask(d);
            if(d & mask){ 
                /*111*/  
                d = addMask(d);
                return 5;
            }else{ 
                /*110*/
                d = addMask(d);
                if(d & mask){   
                    /*1101*/
                    d = addMask(d);
                    return 0;
                }else{  
                    /*1100*/
                    d = addMask(d);
                    if(d & mask){   
                        /*11001*/
                        d = addMask(d);
                        return 7;
                    }else{  
                        /*11000*/
                        d = addMask(d);
                        if(d & mask){  
                            /*110001*/
                            d = addMask(d);
                            return 19;
                        }else{  
                            /*110000*/
                            d = addMask(d);
                            return 20;
                        }
                    }
                }
            }
        }else{  
            /*10*/
            d = addMask(d);
            if(d & mask){   
                /*101*/
                d = addMask(d);
                return 4;
            }else{  
                /*100*/
                d = addMask(d);
                if(d & mask){   
                    /*1001*/
                    d = addMask(d);
                    return 6;
                }else{  
                    /*1000*/
                    d = addMask(d);
                    if(d & mask){   
                        /*10001*/
                        d = addMask(d);
                        if(d & mask){   
                            /*100011*/
                            d = addMask(d);
                            return 8;
                        }else{  
                            /*100010*/
                            d = addMask(d);
                            return 11;
                        }
                    }else{  
                        /*10000*/
                        d = addMask(d);
                        if(d & mask){   
                            /*100001*/
                            d = addMask(d);
                            return 0xff;
                        }else{  
                            /*100000*/
                            d = addMask(d);
                            if(d & mask){   
                                /*1000001*/
                                d = addMask(d);
                                if(d & mask){   
                                    /*10000011*/
                                    d = addMask(d);
                                    return 13;
                                }else{  
                                    /*10000010*/
                                    d = addMask(d);
                                    return 18;
                                }
                            }else{  
                                /*1000000*/
                                d = addMask(d);
                                if(d & mask){  
                                    /*10000001*/
                                    d = addMask(d);
                                    return 9;
                                }else{  
                                    /*10000000*/
                                    d = addMask(d);
                                    return 10;
                                }
                            }
                        }
                    }
                }
            }
        }
    }else{  
        /*0*/
        d = addMask(d);
        if(d & mask){  
            /*01*/
            d = addMask(d);
            if(d & mask){   
                /*011*/
                d = addMask(d);
                return 1;
            }else{  
                /*010*/
                d = addMask(d);
                return 2;
            }
        }else{  
            /*00*/
            d = addMask(d);
            return 3;
        }
    }
}

uint8_t addMask(uint8_t currentValue){
    if(mask == 0x80){
        mask = DEFUALT_MASK;
        dec++;
        return *dec;
    }else{
        mask = mask << 1;
        return currentValue;
    }
}