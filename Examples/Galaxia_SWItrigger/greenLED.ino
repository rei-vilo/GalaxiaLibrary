///
/// @file		greenLED.ino
/// @brief		Task for Energia MT
/// @n
/// @n @b		Project EMT-swi-trigger
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		21/06/2015 12:11
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Core library for code-sense - IDE-based
#if defined(EMBEDXCODE)
#if defined(ENERGIA) && defined(__MSP432P401R__) // LaunchPad MSP432 on Energia MT only
#include "Energia.h"
#else
#error LaunchPad MSP432 on Energia MT only
#endif
#endif // end IDE

// Include application, user and local libraries


// Prototypes


// Define variables and constants


void blink(uint8_t pin, uint8_t times, uint16_t ms)
{
    for (uint8_t i = 0; i < times; i++)
    {
        digitalWrite(pin, HIGH);
        // delay gives focus back to other tasks
        // delay(ms >> 1);
        // delayMicroseconds doesn't seem so
        delayMicroseconds((ms >> 1) * 1000);
        digitalWrite(pin, LOW);
        delayMicroseconds((ms >> 1) * 1000);
    }
}


// Setup
void greenLED_setup()
{
    pinMode(GREEN_LED, OUTPUT);
}

// Loop
void greenLED_loop()
{
    myEvent.waitFor();

    blink(GREEN_LED, 3, 333);

    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    mySemaphore.waitFor();

    Serial.print(millis(), DEC);
    Serial.println("\t4\t*");

    mySemaphore.post();
}

