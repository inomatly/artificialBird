/*
 * File:   MakePwm.c
 * Author: tamag
 *
 * Created on 2024/06/16
 */
#ifndef MAKEPWM_H
#define MAKEPWM_H

#include "DriveLed.h"

void MakePWMformGPIO(int Duty, int SumOfNumeratorAndDenominator,
                     int* LocalStep, int identifier);//
enum DriveTarget { DcMotor, ServoOne, ServoTwo, VisibleLed };

#endif
