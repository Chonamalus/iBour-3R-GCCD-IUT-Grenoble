/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register 32 bits Metadata Builder, only for debugging purpose
==========================================================================================

TO-DO:

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    The RegisterMetaBuilder utilizes the Builder design pattern to create register
metadata step-by-step, making the code more readable and simplifying the register building
process.

Programming techniques and optimization:
    1. Preprocessor directive: The USE_REGISTERS_META defined variable ensures that the
code uses metadata of registers only for debugging, not for deployment in the
microprocessor.
    2. Builder design pattern: This pattern allows for the step-by-step construction of
complex objects, such as register metadata, by separating the construction process from
the object's representation. It improves code readability and maintainability.
*/

#pragma once
#include <stdint.h>

#include "Register32_Meta.h"
#include "config.h"

#ifdef USE_REGISTERS_META
class RegisterMetaBuilder {
   public:
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

    RegisterMeta build() const { return RegisterMeta(accessType, defaultValue, size); }

   private:
    AccessType accessType;
    uint32_t defaultValue;
    uint8_t size;
};
#endif
