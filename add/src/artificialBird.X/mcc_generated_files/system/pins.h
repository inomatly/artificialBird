/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define OUT1_TRIS                 TRISAbits.TRISA0
#define OUT1_LAT                  LATAbits.LATA0
#define OUT1_PORT                 PORTAbits.RA0
#define OUT1_WPU                  WPUAbits.WPUA0
#define OUT1_OD                   ODCONAbits.ODCA0
#define OUT1_ANS                  ANSELAbits.ANSA0
#define OUT1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define OUT1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define OUT1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define OUT1_GetValue()           PORTAbits.RA0
#define OUT1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define OUT1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define OUT1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define OUT1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define OUT1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define OUT1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define OUT1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define OUT1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define PHOTO1_TRIS                 TRISAbits.TRISA1
#define PHOTO1_LAT                  LATAbits.LATA1
#define PHOTO1_PORT                 PORTAbits.RA1
#define PHOTO1_WPU                  WPUAbits.WPUA1
#define PHOTO1_OD                   ODCONAbits.ODCA1
#define PHOTO1_ANS                  ANSELAbits.ANSA1
#define PHOTO1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define PHOTO1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define PHOTO1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define PHOTO1_GetValue()           PORTAbits.RA1
#define PHOTO1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define PHOTO1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define PHOTO1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define PHOTO1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define PHOTO1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define PHOTO1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define PHOTO1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define PHOTO1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
#define RA1_SetInterruptHandler  PHOTO1_SetInterruptHandler
// get/set IO_RA2 aliases
#define PHOTO2_TRIS                 TRISAbits.TRISA2
#define PHOTO2_LAT                  LATAbits.LATA2
#define PHOTO2_PORT                 PORTAbits.RA2
#define PHOTO2_WPU                  WPUAbits.WPUA2
#define PHOTO2_OD                   ODCONAbits.ODCA2
#define PHOTO2_ANS                  ANSELAbits.ANSA2
#define PHOTO2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define PHOTO2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define PHOTO2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define PHOTO2_GetValue()           PORTAbits.RA2
#define PHOTO2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define PHOTO2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define PHOTO2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define PHOTO2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define PHOTO2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define PHOTO2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define PHOTO2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define PHOTO2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RB4 aliases
#define PHOTO3_TRIS                 TRISBbits.TRISB4
#define PHOTO3_LAT                  LATBbits.LATB4
#define PHOTO3_PORT                 PORTBbits.RB4
#define PHOTO3_WPU                  WPUBbits.WPUB4
#define PHOTO3_OD                   ODCONBbits.ODCB4
#define PHOTO3_ANS                  ANSELBbits.ANSB4
#define PHOTO3_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define PHOTO3_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define PHOTO3_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define PHOTO3_GetValue()           PORTBbits.RB4
#define PHOTO3_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define PHOTO3_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define PHOTO3_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define PHOTO3_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define PHOTO3_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define PHOTO3_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define PHOTO3_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define PHOTO3_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define PHOTO4_TRIS                 TRISBbits.TRISB5
#define PHOTO4_LAT                  LATBbits.LATB5
#define PHOTO4_PORT                 PORTBbits.RB5
#define PHOTO4_WPU                  WPUBbits.WPUB5
#define PHOTO4_OD                   ODCONBbits.ODCB5
#define PHOTO4_ANS                  ANSELBbits.ANSB5
#define PHOTO4_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define PHOTO4_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define PHOTO4_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define PHOTO4_GetValue()           PORTBbits.RB5
#define PHOTO4_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define PHOTO4_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define PHOTO4_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define PHOTO4_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define PHOTO4_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define PHOTO4_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define PHOTO4_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define PHOTO4_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)
// get/set IO_RC1 aliases
#define MOTOR_TRIS                 TRISCbits.TRISC1
#define MOTOR_LAT                  LATCbits.LATC1
#define MOTOR_PORT                 PORTCbits.RC1
#define MOTOR_WPU                  WPUCbits.WPUC1
#define MOTOR_OD                   ODCONCbits.ODCC1
#define MOTOR_ANS                  ANSELCbits.ANSC1
#define MOTOR_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define MOTOR_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define MOTOR_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define MOTOR_GetValue()           PORTCbits.RC1
#define MOTOR_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define MOTOR_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define MOTOR_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define MOTOR_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define MOTOR_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define MOTOR_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define MOTOR_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define MOTOR_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC3 aliases
#define SERVO1_TRIS                 TRISCbits.TRISC3
#define SERVO1_LAT                  LATCbits.LATC3
#define SERVO1_PORT                 PORTCbits.RC3
#define SERVO1_WPU                  WPUCbits.WPUC3
#define SERVO1_OD                   ODCONCbits.ODCC3
#define SERVO1_ANS                  ANSELCbits.ANSC3
#define SERVO1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SERVO1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SERVO1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SERVO1_GetValue()           PORTCbits.RC3
#define SERVO1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SERVO1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SERVO1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SERVO1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SERVO1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SERVO1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SERVO1_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define SERVO1_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define SERVO2_TRIS                 TRISCbits.TRISC4
#define SERVO2_LAT                  LATCbits.LATC4
#define SERVO2_PORT                 PORTCbits.RC4
#define SERVO2_WPU                  WPUCbits.WPUC4
#define SERVO2_OD                   ODCONCbits.ODCC4
#define SERVO2_ANS                  ANSELCbits.ANSC4
#define SERVO2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SERVO2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SERVO2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SERVO2_GetValue()           PORTCbits.RC4
#define SERVO2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SERVO2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SERVO2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SERVO2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SERVO2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SERVO2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SERVO2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SERVO2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the PHOTO1 pin functionality
 * @param none
 * @return none
 */
void PHOTO1_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PHOTO1 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for PHOTO1 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void PHOTO1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for PHOTO1 pin.
 *        This is a dynamic interrupt handler to be used together with the PHOTO1_SetInterruptHandler() method.
 *        This handler is called every time the PHOTO1 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*PHOTO1_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PHOTO1 pin. 
 *        This is a predefined interrupt handler to be used together with the PHOTO1_SetInterruptHandler() method.
 *        This handler is called every time the PHOTO1 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void PHOTO1_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/