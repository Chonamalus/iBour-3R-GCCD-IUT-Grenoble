/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register 32 bits Metadata, only for debugging purpose
==========================================================================================

TO-DO:

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    The RegisterMeta class contains what I call the metadata of the registers. Those data
are not needed for the deployed code in microprocessor. But, they are very useful for
development, if I need to check whether I can read, write to a register, or to check the
size of it, or to get the default value of the register.

Programming techniques and optimization:
    1. Preprocessor directive: The USE_REGISTERS_META defined variable ensures that the
code uses metadata of registers only for debugging, not for deployment in the
microprocessor.
    2. Const Keyword: The const keyword indicate to the compiler that the metadata
attributes of a register are not variables, they are data.
*/

#pragma once
#include <stdint.h>

#include "config.h"

#ifdef USE_REGISTERS_META
/* Register access types */
typedef enum { READ, WRITE, READ_WRITE } AccessType;

class RegisterMeta {
   public:
    RegisterMeta(AccessType accessType, uint32_t defaultValue, uint8_t size)
        : accessType(accessType), defaultValue(defaultValue), size(size) {}

    const AccessType accessType;
    const uint32_t defaultValue;
    const uint8_t size;

    // Methods to check register state
    uint32_t getDefaultValue() const { return this->defaultValue; }
    bool isReadable() const { return this->accessType == READ; }
    bool isWritable() const { return this->accessType == WRITE; }
    bool isReadWrite() const { return this->accessType == READ_WRITE; }
    bool isSize32() const { return this->size == 32; }
    bool isSize16() const { return this->size == 16; }
    bool isSize8() const { return this->size == 8; }
};
#endif