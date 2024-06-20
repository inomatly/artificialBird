/**
 * Generated Driver File
 *
 * @file pins.c
 *
 * @ingroup  pinsdriver
 *
 * @brief This is generated driver implementation for pins.
 *        This file provides implementations for pin APIs for all pins selected
 * in the GUI.
 *
 * @version Driver Version 3.0.0
 */

/*
? [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip
    software and any derivatives exclusively with Microchip products.
    You are responsible for complying with 3rd party license terms
    applicable to your use of 3rd party software (including open source
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.?
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.
*/

#include "../pins.h"

#include "../../../headers/DriveLed.h"

void (*PHOTO1_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void) {
    /**
     LATx registers
     */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xFE;
    TRISB = 0xFF;
    TRISC = 0xE5;

    /**
    ANSELx registers
    */
    ANSELA = 0xF8;
    ANSELB = 0xCF;
    ANSELC = 0xE5;

    /**
    WPUx registers
    */
    WPUA = 0x6;
    WPUB = 0x30;
    WPUC = 0x0;
    WPUE = 0x0;

    /**
    ODx registers
    */

    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLE = 0x8;

    /**
    PPS registers
    */
    RC4PPS = 0x0E;  // RC4->PWM6:PWM6OUT;

    /**
    APFCON registers
    */

    /**
     IOCx registers
     */
    IOCAP = 0x2;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    PHOTO1_SetInterruptHandler(PHOTO1_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt
    PIE0bits.IOCIE = 1;
}

void PIN_MANAGER_IOC(void) {
    // interrupt on change for pin PHOTO1}
    if (IOCAFbits.IOCAF1 == 1) {
        PHOTO1_ISR();
    }
}

/**
   PHOTO1 Interrupt Service Routine
*/
void PHOTO1_ISR(void) {
    // Add custom IOCAF1 code

    // Call the interrupt handler for the callback registered at runtime
    if (PHOTO1_InterruptHandler) {
        PHOTO1_InterruptHandler();
    }
    IOCAFbits.IOCAF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF1 at application runtime
*/
void PHOTO1_SetInterruptHandler(void (*InterruptHandler)(void)) {
    PHOTO1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF1
*/
void PHOTO1_DefaultInterruptHandler(void) {
    // add your PHOTO1 interrupt custom code
    // or set custom function using PHOTO1_SetInterruptHandler()
}
/**
 End of File
*/