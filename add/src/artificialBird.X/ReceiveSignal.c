/*
 * File:  ReceiveSinal.c
 * Author: tamag
 *
 * Created on 2024/06/24
 */

#include "headers/ReceiveSignal.h"

#include <stdio.h>
#include <stdlib.h>

#include "headers/ControlMotor.h"

#ifndef CPPUTEST
#include "mcc_generated_files/system/system.h"
#endif

int g_CntCh1 = 0;
int g_CntCh2 = 0;
int g_CntCh3 = 0;
int f_UpdateParam = 0;
int g_SignalState = 0;

/**
 ** @brief 受光素子からの入力をマージして返す関数
 ** @details 謝検出対策の実装は未
 */
int InputMerge(void) {
    int sensor1 = wrPHOTO1_GetValue();
    int sensor2 = wrPHOTO2_GetValue();
    int sensor3 = wrPHOTO3_GetValue();
    int sensor4 = wrPHOTO4_GetValue();

    return sensor1 || sensor2 || sensor3 || sensor4;
}

/**
 ** @brief ReceiveSignal関数の各種変数を初期化する
 ** @details g_CntCh1, g_CntCh2, g_CntCh3, f_UpdateParam, g_SignalState
 */
void InitReceiveSignal(void) {
    g_CntCh1 = 0;
    g_CntCh2 = 0;
    g_CntCh3 = 0;
    g_SignalState = 0;
    f_UpdateParam = 0;
}

/**
 ** @brief 赤外線信号を分析する関数
 ** @details g_CntCh1, g_CntCh2, g_CntCh3, g_SignalState
 *異常系はまた後で設計する
 */
void AnalizeSignal(void) {
    int signal = InputMerge();

    // カウンタの更新
    if (signal) {
        g_SignalState++;
        if (g_SignalState == 6) {  // 終端信号
            f_UpdateParam = 1;
        }
    } else {
        switch (g_SignalState) {
            case 1:
                g_CntCh1++;
                break;
            case 2:
                g_CntCh2++;
                break;
            case 3:
                g_CntCh3++;
                break;
            default:
                printf("default");
                break;
        }
    }

    // パラメータの更新
    if (g_SignalState > 5) {  //
        g_CntCh1 = 0;
        g_CntCh2 = 0;
        g_CntCh3 = 0;
        g_SignalState = 0;
    }
}

/**
 * @brief 各参照値を更新する関数
 */
void UpdateRefs(void) {
    if (f_UpdateParam) {
        DcMotorRef = g_CntCh1;
        ServoARef = g_CntCh2;
        ServoBRef = g_CntCh3;
        f_UpdateParam = 0;  // フラグをリセット
    }
}

#ifndef CPPUTEST

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details PHOTO1_GetValue()
 ** @return bool photo sensor input
 */
int wrPHOTO1_GetValue(void) { return PHOTO1_GetValue(); }

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details PHOTO2_GetValue()
 ** @return bool photo sensor input
 */
int wrPHOTO2_GetValue(void) { return PHOTO2_GetValue(); }

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details PHOTO3_GetValue()
 ** @return bool photo sensor input
 */
int wrPHOTO3_GetValue(void) { return PHOTO3_GetValue(); }

/**
 ** @brief MCCが生成するドライバーマクロのラッパー関数
 ** @details PHOTO4_GetValue()
 ** @return bool photo sensor input
 */
int wrPHOTO4_GetValue(void) { return PHOTO4_GetValue(); }

#endif
