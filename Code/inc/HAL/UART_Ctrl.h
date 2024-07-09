/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - UART Control at Device Abstraction Layer
==========================================================================================

TO-DO:

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    The Device Abstraction Layer (DAL) for UART, is an abstraction to manipulate the
registers of UART only from the groups of UART registers, independently of any other
groups of registers.

Programming techniques and optimization:
    1. Preprocessor directive: The UART_CTRL defined variable, ensures that I will use the
UART functions only of needed by the program.
    2. Inline Functions: The inline keyword suggests to the compiler to expand the
function inline, which eliminates the overhead of function calls.
    3. Const Keyword: The const keyword indicate to the compiler that the metadata
attributes of a register are not variables, they are data.
    4. Facade Design Pattern: The Facade Design Pattern help to create an abstraction, an
API for the develppers, so that it's easier to manipulate the device/module without
thinking of what registers to use.
*/

#pragma once
#include <stdint.h>

#include "ADuC7061_MMR.h"
#include "config.h"

#ifdef UART_CTRL

class UARTCtrl {
   public:
    // Setup the UART communication here
    inline void setBaudRate(const uint16_t baudRate);
    inline void setWordLenght(const uint8_t wordLenght);
    inline void enableStopBit(const bool isThereStopBit);
    inline void setParity(const bool enableParity, const bool isEven);

    // Communicate through UART
    inline void write(uint8_t message);
    inline uint8_t read();

    // Configure the Interrupts for UART here
    inline void enableUartInterrupt(const bool isEnabled);

    // Check if Tx buffer is empty, and Rx buffer full
    inline bool isWritable();
    inline bool isReadable();
};

#endif
