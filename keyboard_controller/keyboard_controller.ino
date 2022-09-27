#include <HID-Project.h>
#include <HID-Settings.h>
//#include "keymap.h"




///Pins
#define K_1 16
#define K_2 15
#define K_3 17
#define K_4 14
#define K_5 1
#define K_6 23
#define K_7 0
#define K_8 NULL
#define K_9 2
#define K_10 22
#define K_11 3
#define K_12 21
#define K_13 4
#define K_14 20
#define K_15 5
#define K_16 19
#define K_17 6
#define K_18 18
#define K_19 7
#define K_20 13
#define K_21 8
#define K_22 11
#define K_23 9
#define K_24 12
#define K_25 NULL
#define K_26 NULL
#define K_27 NULL
#define K_28 NULL


byte testKey = KEY_B;

int row[] = {K_3, K_4, K_6, K_7, K_9, K_10, K_12, K_13};
int col[] = {K_1, K_2, K_5, K_11, K_14, K_15, K_16, K_17, K_18, K_19, K_20, K_21, K_22, K_23, K_24};

void setup() {

    //key matrix setup 
    for (int i = 0; i < sizeof(row)/sizeof(row[0]); i++){
        pinMode(row[i], OUTPUT);
        digitalWrite(row[i], HIGH);
    }
    for (int i = 0; i < sizeof(col)/sizeof(col[0]); i++){
        pinMode(col[i], INPUT_PULLUP);
    }
    
}

void loop() {
    
    for (int i = 0; i < sizeof(row)/sizeof(row[0]); i++){
        digitalWrite(row[i], LOW);
        for (int j = 0; j < sizeof(col)/sizeof(col[0]); j++){
            if (digitalRead(col[j]) == LOW){
                //Keyboard.write('A');
                BootKeyboard.write(testKey);
            }
        }
        digitalWrite(row[i], HIGH);
    }
}