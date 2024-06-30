/*
 * File:   ControlMotor.c
 * Author: tamag
 *
 * Created on 2024/06/24
 */

#include "headers/ControlMotor.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef CPPUTEST
#include "mcc_generated_files/system/system.h"
#endif

int DcMotorRef = 0;
int ServoARef = 0;
int ServoBRef = 0;