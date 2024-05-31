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
#define SW1_TRIS                 TRISAbits.TRISA0
#define SW1_LAT                  LATAbits.LATA0
#define SW1_PORT                 PORTAbits.RA0
#define SW1_WPU                  WPUAbits.WPUA0
#define SW1_OD                   ODCONAbits.ODCA0
#define SW1_ANS                  ANSELAbits.ANSA0
#define SW1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SW1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SW1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SW1_GetValue()           PORTAbits.RA0
#define SW1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SW1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)
#define RA0_SetInterruptHandler  SW1_SetInterruptHandler
// get/set IO_RA1 aliases
#define SW2_TRIS                 TRISAbits.TRISA1
#define SW2_LAT                  LATAbits.LATA1
#define SW2_PORT                 PORTAbits.RA1
#define SW2_WPU                  WPUAbits.WPUA1
#define SW2_OD                   ODCONAbits.ODCA1
#define SW2_ANS                  ANSELAbits.ANSA1
#define SW2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SW2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SW2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SW2_GetValue()           PORTAbits.RA1
#define SW2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SW2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)
#define RA1_SetInterruptHandler  SW2_SetInterruptHandler
// get/set IO_RA2 aliases
#define SW3_TRIS                 TRISAbits.TRISA2
#define SW3_LAT                  LATAbits.LATA2
#define SW3_PORT                 PORTAbits.RA2
#define SW3_WPU                  WPUAbits.WPUA2
#define SW3_OD                   ODCONAbits.ODCA2
#define SW3_ANS                  ANSELAbits.ANSA2
#define SW3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SW3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SW3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SW3_GetValue()           PORTAbits.RA2
#define SW3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SW3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SW3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SW3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SW3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
#define RA2_SetInterruptHandler  SW3_SetInterruptHandler
// get/set IO_RA3 aliases
#define OUT1_TRIS                 TRISAbits.TRISA3
#define OUT1_LAT                  LATAbits.LATA3
#define OUT1_PORT                 PORTAbits.RA3
#define OUT1_WPU                  WPUAbits.WPUA3
#define OUT1_OD                   ODCONAbits.ODCA3
#define OUT1_ANS                  ANSELAbits.ANSA3
#define OUT1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define OUT1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define OUT1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define OUT1_GetValue()           PORTAbits.RA3
#define OUT1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define OUT1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define OUT1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define OUT1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define OUT1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define OUT1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define OUT1_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define OUT1_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)
// get/set IO_RA4 aliases
#define OUT2_TRIS                 TRISAbits.TRISA4
#define OUT2_LAT                  LATAbits.LATA4
#define OUT2_PORT                 PORTAbits.RA4
#define OUT2_WPU                  WPUAbits.WPUA4
#define OUT2_OD                   ODCONAbits.ODCA4
#define OUT2_ANS                  ANSELAbits.ANSA4
#define OUT2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define OUT2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define OUT2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define OUT2_GetValue()           PORTAbits.RA4
#define OUT2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define OUT2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define OUT2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define OUT2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define OUT2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define OUT2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define OUT2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define OUT2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define OUT3_TRIS                 TRISAbits.TRISA5
#define OUT3_LAT                  LATAbits.LATA5
#define OUT3_PORT                 PORTAbits.RA5
#define OUT3_WPU                  WPUAbits.WPUA5
#define OUT3_OD                   ODCONAbits.ODCA5
#define OUT3_ANS                  ANSELAbits.ANSA5
#define OUT3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define OUT3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define OUT3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define OUT3_GetValue()           PORTAbits.RA5
#define OUT3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define OUT3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define OUT3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define OUT3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define OUT3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define OUT3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define OUT3_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define OUT3_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
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
 * @brief Interrupt on Change Handler for the SW1 pin functionality
 * @param none
 * @return none
 */
void SW1_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW1 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW1 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW1 pin.
 *        This is a dynamic interrupt handler to be used together with the SW1_SetInterruptHandler() method.
 *        This handler is called every time the SW1 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW1_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW1 pin. 
 *        This is a predefined interrupt handler to be used together with the SW1_SetInterruptHandler() method.
 *        This handler is called every time the SW1 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW2 pin functionality
 * @param none
 * @return none
 */
void SW2_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW2 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW2 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW2 pin.
 *        This is a dynamic interrupt handler to be used together with the SW2_SetInterruptHandler() method.
 *        This handler is called every time the SW2 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW2_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW2 pin. 
 *        This is a predefined interrupt handler to be used together with the SW2_SetInterruptHandler() method.
 *        This handler is called every time the SW2 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW3 pin functionality
 * @param none
 * @return none
 */
void SW3_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW3 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW3 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW3 pin.
 *        This is a dynamic interrupt handler to be used together with the SW3_SetInterruptHandler() method.
 *        This handler is called every time the SW3 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW3_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW3 pin. 
 *        This is a predefined interrupt handler to be used together with the SW3_SetInterruptHandler() method.
 *        This handler is called every time the SW3 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW3_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/