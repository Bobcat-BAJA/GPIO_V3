/*/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27Q84
        Driver Version    :  2.00
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
#define LED_DATA LATCbits.LATC4  // Assuming RC4 is your LED data pin
#include "mcc_generated_files/mcc.h"
// Macro to send a bit 'b' (either 0 or 1) to the LED data pin
#define send(b) LED_DATA = 1; NOP(); NOP(); NOP(); LED_DATA = b; NOP(); NOP(); NOP(); NOP(); LED_DATA = 0; NOP(); NOP(); NOP(); NOP();
/*
                         Main application
 */
void sendByte(unsigned char b);
void sendRGB(unsigned char r, unsigned char g, unsigned char b);


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
                // Set the LED to Red
        sendRGB(255, 0, 0);   // Red
        __delay_ms(1000);     // Delay for 1 second
 
        // Set the LED to Green
        sendRGB(0, 255, 0);   // Green
        __delay_ms(1000);     // Delay for 1 second
 
        // Set the LED to Blue
        sendRGB(0, 0, 255);   // Blue
        __delay_ms(1000);     // Delay for 1 second
        
        sendRGB(0,0,0);
        __delay_ms(1000);
        
    }
}

// Send out a byte 'b' in WS2812 protocol
void sendByte(unsigned char b) {
    if (b & 0b10000000) { send(1); } else { send(0); }
    if (b & 0b01000000) { send(1); } else { send(0); }
    if (b & 0b00100000) { send(1); } else { send(0); }
    if (b & 0b00010000) { send(1); } else { send(0); }
    if (b & 0b00001000) { send(1); } else { send(0); }
    if (b & 0b00000100) { send(1); } else { send(0); }
    if (b & 0b00000010) { send(1); } else { send(0); }
    if (b & 0b00000001) { send(1); } else { send(0); }
}

// Send red, green, and blue values in WS2812 protocol
void sendRGB(unsigned char r, unsigned char g, unsigned char b) {
    sendByte(g);  // Send green first
    sendByte(r);  // Then red
    sendByte(b);  // Finally blue
}