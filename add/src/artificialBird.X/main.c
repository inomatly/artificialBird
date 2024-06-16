/*
 * MAIN Generated Driver File
 *
 * @file main.c
 *
 * @defgroup main MAIN
 *
 * @brief This is the generated driver implementation file for the MAIN driver.
 *         Receiver side.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "headers/main.h"

#include <stdio.h>

#include "headers/Common.h"
#include "headers/DriveLed.h"
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

int main(void) {
    // g_intA=0;
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to
    // enable the Global High and Low Interrupts If using interrupts in PIC
    // Mid-Range Compatibility Mode you need to enable the Global and
    // Peripheral Interrupts Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    // INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    DriveLed(IoOFF);

    // Disable the Peripheral Interrupts
    // INTERRUPT_PeripheralInterruptDisable();
    Timer1_Start();
    Timer2_Start();

    uint16_t Duty = 700;  // 0~1023
    PWM6_LoadDutyValue(Duty);

    int g_PwmRef = 1;
    while (1) {
        // if (Duty > 1000) {
        //     Duty = 100;
        //  DriveLed(IoTOGGLE);
        //}
        PWM6_LoadDutyValue(Duty);
        debug_wait(100000);
        // Duty = Duty + 100;
        g_PwmRef++;
        if (g_PwmRef > 5) {
            g_PwmRef = 1;
        }
    }
}

void debug_wait(long max) {
    for (long i = 0; i < max; i++) {
        ;
    }
}
