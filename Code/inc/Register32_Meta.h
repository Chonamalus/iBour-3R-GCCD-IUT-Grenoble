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

// Ensures that registers metadata is only used for debugging purpose, not for code
// deployment in microprocessor
#ifdef DEBUG
#define USE_REGISTERS_META
#endif

#ifdef USE_REGISTERS_META
/* Register access types */
typedef enum { READ, WRITE, READ_WRITE } AccessType;

class RegisterMeta {
   public:
    RegisterMeta(uint32_t address, AccessType accessType, uint32_t defaultValue,
                 uint8_t size)
        : address(address),
          accessType(accessType),
          defaultValue(defaultValue),
          size(size) {}

    uint32_t address;
    AccessType accessType;
    uint32_t defaultValue;
    uint8_t size;
};
#endif