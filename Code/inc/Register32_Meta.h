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
#define ACCESS_TYPE
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