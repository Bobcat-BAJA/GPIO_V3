/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Mtr1 aliases
#define Mtr1_TRIS                 TRISAbits.TRISA0
#define Mtr1_LAT                  LATAbits.LATA0
#define Mtr1_PORT                 PORTAbits.RA0
#define Mtr1_WPU                  WPUAbits.WPUA0
#define Mtr1_OD                   ODCONAbits.ODCA0
#define Mtr1_ANS                  ANSELAbits.ANSELA0
#define Mtr1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Mtr1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Mtr1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Mtr1_GetValue()           PORTAbits.RA0
#define Mtr1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Mtr1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Mtr1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Mtr1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Mtr1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Mtr1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Mtr1_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define Mtr1_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set Mtr2 aliases
#define Mtr2_TRIS                 TRISAbits.TRISA1
#define Mtr2_LAT                  LATAbits.LATA1
#define Mtr2_PORT                 PORTAbits.RA1
#define Mtr2_WPU                  WPUAbits.WPUA1
#define Mtr2_OD                   ODCONAbits.ODCA1
#define Mtr2_ANS                  ANSELAbits.ANSELA1
#define Mtr2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Mtr2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Mtr2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Mtr2_GetValue()           PORTAbits.RA1
#define Mtr2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Mtr2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Mtr2_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define Mtr2_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define Mtr2_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define Mtr2_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define Mtr2_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define Mtr2_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set dif8 aliases
#define dif8_TRIS                 TRISAbits.TRISA2
#define dif8_LAT                  LATAbits.LATA2
#define dif8_PORT                 PORTAbits.RA2
#define dif8_WPU                  WPUAbits.WPUA2
#define dif8_OD                   ODCONAbits.ODCA2
#define dif8_ANS                  ANSELAbits.ANSELA2
#define dif8_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define dif8_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define dif8_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define dif8_GetValue()           PORTAbits.RA2
#define dif8_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define dif8_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define dif8_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define dif8_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define dif8_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define dif8_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define dif8_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define dif8_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set dif9 aliases
#define dif9_TRIS                 TRISAbits.TRISA3
#define dif9_LAT                  LATAbits.LATA3
#define dif9_PORT                 PORTAbits.RA3
#define dif9_WPU                  WPUAbits.WPUA3
#define dif9_OD                   ODCONAbits.ODCA3
#define dif9_ANS                  ANSELAbits.ANSELA3
#define dif9_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define dif9_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define dif9_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define dif9_GetValue()           PORTAbits.RA3
#define dif9_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define dif9_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define dif9_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define dif9_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define dif9_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define dif9_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define dif9_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define dif9_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set dif1 aliases
#define dif1_TRIS                 TRISAbits.TRISA4
#define dif1_LAT                  LATAbits.LATA4
#define dif1_PORT                 PORTAbits.RA4
#define dif1_WPU                  WPUAbits.WPUA4
#define dif1_OD                   ODCONAbits.ODCA4
#define dif1_ANS                  ANSELAbits.ANSELA4
#define dif1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define dif1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define dif1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define dif1_GetValue()           PORTAbits.RA4
#define dif1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define dif1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define dif1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define dif1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define dif1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define dif1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define dif1_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define dif1_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set dif3 aliases
#define dif3_TRIS                 TRISAbits.TRISA5
#define dif3_LAT                  LATAbits.LATA5
#define dif3_PORT                 PORTAbits.RA5
#define dif3_WPU                  WPUAbits.WPUA5
#define dif3_OD                   ODCONAbits.ODCA5
#define dif3_ANS                  ANSELAbits.ANSELA5
#define dif3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define dif3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define dif3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define dif3_GetValue()           PORTAbits.RA5
#define dif3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define dif3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define dif3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define dif3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define dif3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define dif3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define dif3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define dif3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set channel_ANA6 aliases
#define channel_ANA6_TRIS                 TRISAbits.TRISA6
#define channel_ANA6_LAT                  LATAbits.LATA6
#define channel_ANA6_PORT                 PORTAbits.RA6
#define channel_ANA6_WPU                  WPUAbits.WPUA6
#define channel_ANA6_OD                   ODCONAbits.ODCA6
#define channel_ANA6_ANS                  ANSELAbits.ANSELA6
#define channel_ANA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define channel_ANA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define channel_ANA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define channel_ANA6_GetValue()           PORTAbits.RA6
#define channel_ANA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define channel_ANA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define channel_ANA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define channel_ANA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define channel_ANA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define channel_ANA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define channel_ANA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define channel_ANA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set dif4 aliases
#define dif4_TRIS                 TRISAbits.TRISA7
#define dif4_LAT                  LATAbits.LATA7
#define dif4_PORT                 PORTAbits.RA7
#define dif4_WPU                  WPUAbits.WPUA7
#define dif4_OD                   ODCONAbits.ODCA7
#define dif4_ANS                  ANSELAbits.ANSELA7
#define dif4_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define dif4_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define dif4_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define dif4_GetValue()           PORTAbits.RA7
#define dif4_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define dif4_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define dif4_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define dif4_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define dif4_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define dif4_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define dif4_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define dif4_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set speed_slct aliases
#define speed_slct_TRIS                 TRISBbits.TRISB1
#define speed_slct_LAT                  LATBbits.LATB1
#define speed_slct_PORT                 PORTBbits.RB1
#define speed_slct_WPU                  WPUBbits.WPUB1
#define speed_slct_OD                   ODCONBbits.ODCB1
#define speed_slct_ANS                  ANSELBbits.ANSELB1
#define speed_slct_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define speed_slct_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define speed_slct_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define speed_slct_GetValue()           PORTBbits.RB1
#define speed_slct_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define speed_slct_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define speed_slct_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define speed_slct_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define speed_slct_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define speed_slct_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define speed_slct_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define speed_slct_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set LED_DATA aliases
#define LED_DATA_TRIS                 TRISCbits.TRISC4
#define LED_DATA_LAT                  LATCbits.LATC4
#define LED_DATA_PORT                 PORTCbits.RC4
#define LED_DATA_WPU                  WPUCbits.WPUC4
#define LED_DATA_OD                   ODCONCbits.ODCC4
#define LED_DATA_ANS                  ANSELCbits.ANSELC4
#define LED_DATA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED_DATA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED_DATA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED_DATA_GetValue()           PORTCbits.RC4
#define LED_DATA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED_DATA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED_DATA_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED_DATA_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED_DATA_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED_DATA_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED_DATA_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define LED_DATA_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/