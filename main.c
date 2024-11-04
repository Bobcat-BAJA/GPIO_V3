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
#define CAN_MESSAGE_ID 0x100   // Replace with your desired CAN 
#define LED_DATA LATCbits.LATC4  // Assuming RC4 is your LED data pin
#include "mcc_generated_files/mcc.h"
// Macro to send a bit 'b' (either 0 or 1) to the LED data pin
#define send(b) LED_DATA = 1; NOP(); NOP(); NOP(); LED_DATA = b; NOP(); NOP(); NOP(); NOP(); LED_DATA = 0; NOP(); NOP(); NOP(); NOP();
/*
                         Main application
 */


// Declaration to send a byte in WS2812 protocol
void sendByte(unsigned char b);

// Declaration to send red, green, and blue values in WS2812 protocol
void sendRGB(unsigned char r, unsigned char g, unsigned char b);

// Function for determining the state of the switch command
void get_switch_state();

// Enum for differential states
enum dif_state {locked, semi, open, undefined};

// Enum for motor directions
enum motor_direction {clockwise, counterclockwise, stop};

// Function to control motor movement direction based on differential state
void change_dif_state(enum dif_state new_state);

// Function for determining Diff State and sending correct color to LED
enum dif_state get_top_dif_state();

// Function for controlling motor movement
void run_motor(enum motor_direction mtr_dir);

// Function to run LED through test sequence
void ledtest();

//Function to send CAN data
void sendArrayOverCAN(uint8_t* data_array, int data_array_length);

void main(void) {
    run_motor(stop);  // Stop the motor 
    SYSTEM_Initialize();  // Initialize system

    while (1) {
        __delay_ms(50);
        change_dif_state(open);
        __delay_ms(3000);
        change_dif_state(locked);
        __delay_ms(3000);
        change_dif_state(semi);
        __delay_ms(3000);
        
        __delay_ms(50);
        get_switch_state();
        
        // Run LED test sequence
        ledtest();
        
        uint8_t my_data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140};
        int data_length = sizeof(my_data) / sizeof(my_data[0]);

        // Call the function to send the array over CAN
        sendArrayOverCAN(my_data, data_length);
    }
}

// Function to determine the state of the switch using ADC
void get_switch_state() {
    uint16_t convertedValue;
    ADC_StartConversion(RA6);  // Start ADC conversion on pin RA6
    while (!ADC_IsConversionDone());  // Wait for ADC conversion to finish
    convertedValue = ADC_GetConversionResult();

    // Set differential state based on ADC result ranges
    if (convertedValue <= 3010 && convertedValue >= 2300) {
        change_dif_state(semi);  // Semi state
    } else if (convertedValue > 3010) {
        change_dif_state(open);  // Open state
    } else if (convertedValue < 2300 && convertedValue > 1000) {
        change_dif_state(locked);  // Locked state
    }
}

// Function to control motor movement direction based on differential state
void change_dif_state(enum dif_state new_state) {
    enum motor_direction mtr_dir;
    enum dif_state start_state = get_top_dif_state();

    // Set motor direction based on target and current state
    if (new_state == locked || (new_state == semi && start_state == open)) {
        mtr_dir = clockwise;
    } else {
        mtr_dir = counterclockwise;
    }

    // Run motor until target state is reached
    while (get_top_dif_state() != new_state) {
        run_motor(mtr_dir);
    }

    run_motor(stop);  // Stop motor once in the desired state
}

// Function to determine and display the current differential state
enum dif_state get_top_dif_state() {
    if (dif4_GetValue() == 1 && dif3_GetValue() == 0 && dif1_GetValue() == 0) {
        sendRGB(0, 255, 0);  // Green for open
        return open;
    }
    if (dif4_GetValue() == 1 && dif3_GetValue() == 1 && dif1_GetValue() == 0) {
        sendRGB(0, 0, 255);  // Blue for semi
        return semi;
    }
    if (dif4_GetValue() == 0 && dif3_GetValue() == 1 && dif1_GetValue() == 1) {
        sendRGB(255, 0, 0);  // Red for locked
        return locked;
    } else {
        sendRGB(0, 0, 0);  // Off for undefined state
        return undefined;
    }
}

// Function to control motor movement and direction
void run_motor(enum motor_direction mtr_dir) {
    switch (mtr_dir) {
        case stop:
            Mtr1_SetLow();
            Mtr2_SetLow();
            break;
        case clockwise:
            Mtr1_SetHigh();
            Mtr2_SetLow();
            break;
        case counterclockwise:
            Mtr1_SetLow();
            Mtr2_SetHigh();
            break;
    }
}

// Function to send out a byte 'b' in WS2812 protocol
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

// Function to send red, green, and blue values in WS2812 protocol
void sendRGB(unsigned char r, unsigned char g, unsigned char b) {
    sendByte(g);  // Send green first
    sendByte(r);  // Then red
    sendByte(b);  // Finally blue
}

// Function to run LED through test sequence
void ledtest() {
    sendRGB(255, 0, 0);  // Red
    __delay_ms(1000);
    sendRGB(0, 255, 0);  // Green
    __delay_ms(1000);
    sendRGB(0, 0, 255);  // Blue
    __delay_ms(1000);
    sendRGB(0, 0, 0);    // Off
    __delay_ms(1000);
}

void sendArrayOverCAN(uint8_t* data_array, int data_array_length) {
    CAN_MSG_OBJ msg;  // CAN message object
    msg.field.idType = CAN_FRAME_STD;  // Standard 11-bit identifier
    msg.msgId = CAN_MESSAGE_ID;        // Set CAN message ID

    // Loop through the array in 8-byte chunks
    for (int i = 0; i < data_array_length; i += 8) {
        // Load up to 8 bytes of data into the CAN message
        for (int j = 0; j < 8 && (i + j) < data_array_length; j++) {
            msg.data[j] = data_array[i + j];
        }

        // Set the data length code (dlc) for this frame
        msg.field.dlc = (data_array_length - i < 8) ? (data_array_length - i) : 8;

        // Send the CAN message using MCC's CAN_transmit function
        if (CAN_transmit(&msg) != 0) { // Check for successful transmission
            // Error handling if the message fails to send
            // You could add a retry mechanism or log the error
        }
    }
}