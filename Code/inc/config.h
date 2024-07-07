/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Configurator for debugging purpose, and includes
==========================================================================================

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    This file contains all the including files of the project. Also it contains
preprocessor defined variables for debugging purpose only. One should only include this
file in the main.cpp file to compile and run the project.
*/

/*
    Define DEBUG during development to include metadata and other debug-related
   information in the build. When ready to compile the code for deployment on the
   microprocessor, please ensure that DEBUG is not defined, to exclude the metadata and
   other debug-related code.
*/
#define DEBUG

/*
    Only define the set of registers that will be used in the final code.
*/
#define INTERRUPT_CTRL
#define REMAP_CTRL
#define TIMER_0_CTRL
#define TIMER_1_CTRL  // or WAKE UP TIMER
#define TIMER_2_CTRL  // or WATCHDOG TIMER
#define TIMER_3_CTRL
#define PLL_AND_CLOCK_CTRL
#define ADC_CTRL
#define DAC_CTRL
#define UART_CTRL
#define I2C_CTRL
#define SPI_CTRL
#define GPIO_CTRL
#define FLASH_CTRL
#define PWM_CTRL


/*
    Preprocessor arithmetic
*/
#ifdef DEBUG
#define USE_REGISTERS_META
#endif

// All the project necessary included files
#pragma once
#include <iostream>

#include "ADuC7061_registers.h"
#include "Register32_Interface.h"
#include "Register32_Meta.h"
#include "Register32_MetaBuilder.h"