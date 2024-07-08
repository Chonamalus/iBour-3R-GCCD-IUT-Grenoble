/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Configurator for debugging purpose
==========================================================================================

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    This file contains preprocessor defined variables:
    - There is DEBUG mode enabled if DEBUG is defined, which means the code is made to be
compiled by g++ on a computer.
    - There is all the defined CTRL variables that represents each set of registers.
Enable the ones you use, and comment out the ones you don't need for your final code.
    - There is preprocessor arithmetic, that enables differents part of the code, if debug
mode is enabled. So that, it is much more dynamic for development purpose.
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
#define TESTER              // Use the test file
#define USE_REGISTERS_META  // Use the registers metadata
#endif