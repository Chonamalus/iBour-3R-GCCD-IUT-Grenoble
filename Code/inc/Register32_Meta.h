/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register 32 bits Metadata, only for debugging purpose
==========================================================================================

TO-DO:
    §§§§

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    §§§§

Programming techniques and optimization:
    §§§§
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