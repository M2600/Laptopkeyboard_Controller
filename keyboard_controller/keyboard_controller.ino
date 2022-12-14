//#include <HID-Project.h>
//#include <HID-Settings.h>
#include "keymap.h"




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



int row[] = {K_3, K_4, K_6, K_7, K_9, K_10, K_12, K_13};
int col[] = {K_1, K_2, K_5, K_11, K_14, K_15, K_16, K_17, K_18, K_19, K_20, K_21, K_22, K_23, K_24};

bool currentKeyState[8][15];
bool beforeKeyState[8][15];
bool fnKeyEnable = false;

void setup() {

    //key matrix setup 
    for (int i = 0; i < sizeof(row)/sizeof(row[0]); i++){
        pinMode(row[i], OUTPUT);
        digitalWrite(row[i], HIGH);
    }
    for (int i = 0; i < sizeof(col)/sizeof(col[0]); i++){
        pinMode(col[i], INPUT_PULLUP);
    }

    //keyboard setup
    for(int i = 0; i < sizeof(currentKeyState)/sizeof(currentKeyState[0]); i++){
        for(int j = 0; j < sizeof(currentKeyState[0])/sizeof(currentKeyState[0][0]); j++){
            currentKeyState[i][j] = true;
            beforeKeyState[i][j] = true;
        }
    }
    
}

void loop() {
    
    for (int i = 0; i < sizeof(row)/sizeof(row[0]); i++){
        digitalWrite(row[i], LOW);
        for (int j = 0; j < sizeof(col)/sizeof(col[0]); j++){
             currentKeyState[i][j] = digitalRead(col[j]);
            if(currentKeyState[i][j] != beforeKeyState[i][j]){
                int mapKey = 0;
                //Change keymap
                if(fnKeyEnable)
                {
                    mapKey = 8;
                }
                if(currentKeyState[i][j] == LOW){
                    if(keymap[i + mapKey][j] == KEY_FN){
                        fnKeyEnable = true;
                        BootKeyboard.releaseAll();
                    }
                    else
                    {
                        BootKeyboard.press(keymap[i + mapKey][j]);
                    }
                    beforeKeyState[i][j] = false;
                }else{
                    if(keymap[i + mapKey][j] == KEY_FN){
                        fnKeyEnable = false;
                        BootKeyboard.releaseAll();
                    }
                    else
                    {
                        BootKeyboard.release(keymap[i + mapKey][j]);
                    }
                    beforeKeyState[i][j] = true;
                }
            }
        }
        digitalWrite(row[i], HIGH);
    }
}