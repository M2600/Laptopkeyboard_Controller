#include <HID-Project.h>
#include <HID-Settings.h>

/// Pins
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

int pins[] = {K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_9, K_10, 
              K_11, K_12, K_13, K_14, K_15,K_16, K_17, K_18, 
              K_19, K_20, K_21, K_22, K_23, K_24};

String keyName[] = {"key_1", "key_2", "key_3", "key_4", "key_5", "key_6", "key_7", "key_9", "key_10", 
              "key_11", "key_12", "key_13", "key_14", "key_15","key_16", "key_17", "key_18", 
              "key_19", "key_20", "key_21", "key_22", "key_23", "key_24"};

void setup()
{
    for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }

    Serial.begin(9600);
}

void loop()
{
    for(int i = 0; i < sizeof(pins)/sizeof(pins[0]); i++)
    {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
        for(int j = 0; j < i; j++)
        {
            if(digitalRead(pins[j]) == LOW)
            {   
                Serial.print(keyName[j]);
                Serial.print(" ");
                Serial.println(keyName[i]);
            }
            else
            { 
                //Serial.println();
            }
            
        }
        pinMode(pins[i], INPUT_PULLUP);
    }
}
