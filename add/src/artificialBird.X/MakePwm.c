/*
 * File:  DriveLed.c
 * Author: tamag
 *
 * Created on 2024/02/12, 18:59
 */
#include "headers/MakePwm.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef CPPUTEST
#include "mcc_generated_files/system/system.h"
#endif

/**
 * @brief PWM信号を生成する関数
 * @param Duty Duty/分母
 * @param SumOfNumeratorAndDenominator 分子+分母
 * @param LocalStep 複数のPWMを生成する場合に分割するための入力。ポインタ
 * @return none
 */
void MakePWMformGPIO(int Duty, int SumOfNumeratorAndDenominator, int* LocalStep,
                     int identifier) {
    int RwmRef = 0;
    int Step = *LocalStep;
    RwmRef = (int)(SumOfNumeratorAndDenominator * Duty / 100);
    if ((Step < RwmRef) && (Step >= 0)) {
        DriveLed(IoON);
    } else {
        DriveLed(IoOFF);
    }
    if (Step == SumOfNumeratorAndDenominator - 1) {
        Step = 0;
    }
    *LocalStep = Step + 1;
}
