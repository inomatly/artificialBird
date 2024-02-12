/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
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

void (*SW1_InterruptHandler)(void);
void (*SW2_InterruptHandler)(void);
void (*SW3_InterruptHandler)(void);
void (*OUT1_InterruptHandler)(void);
void (*OUT2_InterruptHandler)(void);
void (*OUT3_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xC7;
    TRISB = 0xFF;
    TRISC = 0xFF;

    /**
    ANSELx registers
    */
    ANSELA = 0xC0;
    ANSELB = 0xFF;
    ANSELC = 0xFF;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
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

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x3F;
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

    SW1_SetInterruptHandler(SW1_DefaultInterruptHandler);
    SW2_SetInterruptHandler(SW2_DefaultInterruptHandler);
    SW3_SetInterruptHandler(SW3_DefaultInterruptHandler);
    OUT1_SetInterruptHandler(OUT1_DefaultInterruptHandler);
    OUT2_SetInterruptHandler(OUT2_DefaultInterruptHandler);
    OUT3_SetInterruptHandler(OUT3_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin SW1}
    if(IOCAFbits.IOCAF0 == 1)
    {
        SW1_ISR();  
    }
    // interrupt on change for pin SW2}
    if(IOCAFbits.IOCAF1 == 1)
    {
        SW2_ISR();  
    }
    // interrupt on change for pin SW3}
    if(IOCAFbits.IOCAF2 == 1)
    {
        SW3_ISR();  
    }
    // interrupt on change for pin OUT1}
    if(IOCAFbits.IOCAF3 == 1)
    {
        OUT1_ISR();  
    }
    // interrupt on change for pin OUT2}
    if(IOCAFbits.IOCAF4 == 1)
    {
        OUT2_ISR();  
    }
    // interrupt on change for pin OUT3}
    if(IOCAFbits.IOCAF5 == 1)
    {
        OUT3_ISR();  
    }
}
   
/**
   SW1 Interrupt Service Routine
*/
void SW1_ISR(void) {

    // Add custom IOCAF0 code

    // Call the interrupt handler for the callback registered at runtime
    if(SW1_InterruptHandler)
    {
        SW1_InterruptHandler();
    }
    IOCAFbits.IOCAF0 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF0 at application runtime
*/
void SW1_SetInterruptHandler(void (* InterruptHandler)(void)){
    SW1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF0
*/
void SW1_DefaultInterruptHandler(void){
    // add your SW1 interrupt custom code
    // or set custom function using SW1_SetInterruptHandler()
}
   
/**
   SW2 Interrupt Service Routine
*/
void SW2_ISR(void) {

    // Add custom IOCAF1 code

    // Call the interrupt handler for the callback registered at runtime
    if(SW2_InterruptHandler)
    {
        SW2_InterruptHandler();
    }
    IOCAFbits.IOCAF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF1 at application runtime
*/
void SW2_SetInterruptHandler(void (* InterruptHandler)(void)){
    SW2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF1
*/
void SW2_DefaultInterruptHandler(void){
    // add your SW2 interrupt custom code
    // or set custom function using SW2_SetInterruptHandler()
}
   
/**
   SW3 Interrupt Service Routine
*/
void SW3_ISR(void) {

    // Add custom IOCAF2 code

    // Call the interrupt handler for the callback registered at runtime
    if(SW3_InterruptHandler)
    {
        SW3_InterruptHandler();
    }
    IOCAFbits.IOCAF2 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF2 at application runtime
*/
void SW3_SetInterruptHandler(void (* InterruptHandler)(void)){
    SW3_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF2
*/
void SW3_DefaultInterruptHandler(void){
    // add your SW3 interrupt custom code
    // or set custom function using SW3_SetInterruptHandler()
}
   
/**
   OUT1 Interrupt Service Routine
*/
void OUT1_ISR(void) {

    // Add custom IOCAF3 code

    // Call the interrupt handler for the callback registered at runtime
    if(OUT1_InterruptHandler)
    {
        OUT1_InterruptHandler();
    }
    IOCAFbits.IOCAF3 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF3 at application runtime
*/
void OUT1_SetInterruptHandler(void (* InterruptHandler)(void)){
    OUT1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF3
*/
void OUT1_DefaultInterruptHandler(void){
    // add your OUT1 interrupt custom code
    // or set custom function using OUT1_SetInterruptHandler()
}
   
/**
   OUT2 Interrupt Service Routine
*/
void OUT2_ISR(void) {

    // Add custom IOCAF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(OUT2_InterruptHandler)
    {
        OUT2_InterruptHandler();
    }
    IOCAFbits.IOCAF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF4 at application runtime
*/
void OUT2_SetInterruptHandler(void (* InterruptHandler)(void)){
    OUT2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF4
*/
void OUT2_DefaultInterruptHandler(void){
    // add your OUT2 interrupt custom code
    // or set custom function using OUT2_SetInterruptHandler()
}
   
/**
   OUT3 Interrupt Service Routine
*/
void OUT3_ISR(void) {

    // Add custom IOCAF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(OUT3_InterruptHandler)
    {
        OUT3_InterruptHandler();
    }
    IOCAFbits.IOCAF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF5 at application runtime
*/
void OUT3_SetInterruptHandler(void (* InterruptHandler)(void)){
    OUT3_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF5
*/
void OUT3_DefaultInterruptHandler(void){
    // add your OUT3 interrupt custom code
    // or set custom function using OUT3_SetInterruptHandler()
}
/**
 End of File
*/