/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register 32 bits Metadata Builder, only for debugging purpose
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

#include "Register32_Meta.h"
#include "config.h"

#ifdef USE_REGISTERS_META
#ifdef ACCESS_TYPE
class RegisterMetaBuilder {
   public:
    RegisterMetaBuilder& setAddress(uint32_t address) {
        this->address = address;
        return *this;
    }

    RegisterMetaBuilder& setAccessType(AccessType accessType) {
        this->accessType = accessType;
        return *this;
    }

    RegisterMetaBuilder& setDefaultValue(uint32_t defaultValue) {
        this->defaultValue = defaultValue;
        return *this;
    }

    RegisterMetaBuilder& setSize(uint8_t size) {
        this->size = size;
        return *this;
    }

    RegisterMeta build() const {
        return RegisterMeta(address, accessType, defaultValue, size);
    }

   private:
    uint32_t address;
    AccessType accessType;
    uint32_t defaultValue;
    uint8_t size;
};
#endif
#endif
