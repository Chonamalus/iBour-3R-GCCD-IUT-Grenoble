/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Configurator for debugging purpose
==========================================================================================

TO-DO:
    - Define an arithmetic for each module, since some of the registers groups are used in
other groups, the goal is to have independent modules.

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    This file contains preprocessor defined variables:
    - There is DEBUG mode enabled if DEBUG is defined, which means the code is made to be
compiled by g++ on a computer.
    - There is all the defined CTRL variables that represents each group of registers.
Some groups will be used in many modules, the modules are independent.
    - There is preprocessor debugging arithmetic, that enables differents parts of the
code, if debug mode is enabled. So that, it is much more dynamic for development purpose.
*/

/*
    Define DEBUG during development to include metadata and other debug-related
   information in the build. When ready to compile the code for deployment on the
   microprocessor, please ensure that DEBUG is not defined, to exclude the metadata and
   other debug-related code.
*/
#define DEBUG

/*
    Define the modules needed in your code here
*/

/*
    Only define the group of registers that will be used in the final code. (there will be
   arithmetic here in the future)
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
    Define your preprocessor debugging arithmetic here
*/
#ifdef DEBUG
#define USE_REGISTERS_META  // Use the registers metadata
#endif