/*
 * File:   ReceiveSinal.c
 * Author: tamag
 *
 * Created on 2024/06/24
 */
#ifndef RECEIVESIGNAL_H
#define RECEIVESIGNAL_H

extern int g_CntCh1;
extern int g_CntCh2;
extern int g_CntCh3;
extern int f_UpdateParam;
extern int g_SignalState;

int wrPHOTO1_GetValue(void);
int wrPHOTO2_GetValue(void);
int wrPHOTO3_GetValue(void);
int wrPHOTO4_GetValue(void);
int InputMerge(void);
void InitReceiveSignal(void);
void AnalizeSignal(void);
void UpdateRefs(void);

#ifdef CPPUTEST
#define PHOTO1_SetHigh() \
    { ; }
#define PHOTO2_SetHigh() \
    { ; }
#define PHOTO3_SetHigh() \
    { ; }
#define PHOTO4_SetHigh() \
    { ; }

#endif

#endif //RECEIVESIGNAL_H