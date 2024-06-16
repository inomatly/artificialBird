/*
 * File:   DriveLed.c
 * Author: tamag
 *
 * Created on 2024/02/12, 18:59
 */
#ifndef DRIVELED_H
#define DRIVELED_H

// extern int g_step;
extern int g_PwmRef;

int DriveLed(int onoff);
void wrLED1_SetHigh(void);
void wrLED1_SetLow(void);
void wrLED1_Toggle(void);
void MakePWMformGPIO(int Duty, int SumOfNumeratorAndDenominator,
                     int* LocalStep);
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