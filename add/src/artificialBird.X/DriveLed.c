/*
 * File:  DriveLed.c
 * Author: tamag
 *
 * Created on 2024/02/12, 18:59
 */

#include "headers/DriveLed.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef CPPUTEST
#include "mcc_generated_files/system/system.h"
#endif

/**
 ** @brief LEDを一括で制御する関数 ※今はLEDは1つだが，今後は10個くらいつける予定
 ** @details
 ** @param onoff IoControlの値を用いること
 ** @return 1: 無効な入力
 **         0: 正常な入力
 */
int DriveLed(int onoff) {
    switch (onoff) {
        case IoON:
            wrLED1_SetHigh();
            break;
        case IoOFF:
            wrLED1_SetLow();
            break;
        case IoTOGGLE:
            wrLED1_Toggle();
            break;
        default:
            return 1;
    }
    return 0;
}

#ifndef CPPUTEST
/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details OUT1_SetHigh()
 */
void wrLED1_SetHigh(void) { OUT1_SetHigh(); }

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details OUT1_SetLow()
 */
void wrLED1_SetLow(void) { OUT1_SetLow(); }

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details OUT1_Toggle()
 */
void wrLED1_Toggle(void) { OUT1_Toggle(); }
#endif