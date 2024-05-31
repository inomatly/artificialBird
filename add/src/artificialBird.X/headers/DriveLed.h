/*
 * File:   DriveLed.c
 * Author: tamag
 *
 * Created on 2024/02/12, 18:59
 */
#ifndef DRIVELED_H
#define DRIVELED_H

int DriveLed(int onoff);
void wrLED1_SetHigh(void);
void wrLED1_SetLow(void);
void wrLED1_Toggle(void);

enum IoControl { IoON, IoOFF, IoTOGGLE };

#ifdef CPPUTEST
#define OUT1_SetHigh() \
    { ; }
#define OUT1_SetLow() \
    { ; }
#define OUT1_Toggle() \
    { ; }
#endif

#endif  // DRIVELED_H