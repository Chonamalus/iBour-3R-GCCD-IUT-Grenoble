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
#define INTERRUPT_CONTROLLER
#define REMAP_SYS_CONTROL



#ifdef DEBUG
#define USE_REGISTERS_META  // Registers Metadata only for debugging, not for deployment
#endif

// All the project necessary included files
#pragma once
#include <iostream>

#include "ADuC7061_registers.h"
#include "Register32_Interface.h"
#include "Register32_Meta.h"
#include "Register32_MetaBuilder.h"