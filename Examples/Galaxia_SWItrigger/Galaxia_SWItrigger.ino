///
/// @mainpage	Galaxia SWI Trigger Libarry
///
/// @details	Galaxia SWI Trigger example for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 17:06
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		Galaxia_SWItrigger.ino
/// @brief		Main sketch
///
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		20/06/2015 17:06
/// @version	102
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#include "rtosGlobals.h"
//#include "SWI.h"

// Prototypes


// Define variables and constants
//bool flag = false;

// Setup
void setup()
{
    delay(30);
    /*
        pinMode(PUSH2, INPUT_PULLUP);
        pinMode(RED_LED, OUTPUT);
    */
}

// Loop
void loop()
{
    mySemaphore.waitFor();

    Serial.print(millis(), DEC);
    Serial.print("\t1\t");
    Serial.println(chrono, DEC);

    mySemaphore.post();

    delay(100);
}


