/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register Interface 32bits
==========================================================================================

TO-DO:

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    The Register interface is created to manipulate either the entire 32bits register or
to manipulate each bytes of it, represented by the SubRegisters. It is usefull because
sometimes, the entire 32 bits of data in one address isn't used, but just some part of it.
Slicing the memory, makes it simpler to manipulate. It is possible to read and write to
the entire register, or just to its subregisters.
    Contains metadata attributes and members, for debugging purpose, so that I can be
sure, in my code, that I'm running a clean code.

Programming techniques and optimization:
    1. Volatile Keyword: The volatile keyword ensures that the compiler does not optimize
away the access to the register, which is important for memory-mapped I/O.
    2. Inline Functions: The inline keyword suggests to the compiler to expand the
function inline, which eliminates the overhead of function calls.
    3. Preprocessor directive: The USE_REGISTERS_META defined variable ensures that the
code uses metadata of registers only for debugging, not for deployment in the
microprocessor.
*/

#pragma once
#include <stdint.h>

#include "Register32_Meta.h"
#include "config.h"

/*
    The SubRegister class slicing the 32 bits register
*/
class SubRegister {
   public:
    inline SubRegister(volatile uint32_t *regAddress, uint32_t mask, uint8_t shift) {
        this->regAddress = regAddress;
        this->mask = mask;
        this->shift = shift;
    };

    inline uint8_t read() const {  // Read the sub-register, byte
        return (*regAddress & mask) >> shift;
    };
    inline void write(uint8_t value) {  // Write to the sub-register, byte
        *regAddress = (*regAddress & ~mask) | ((value << shift) & mask);
    };

   private:
    volatile uint32_t *regAddress;  // Address of the main 32-bit register
    uint32_t mask;                  // Mask for the sub-register
    uint8_t shift;                  // Bit shift for the sub-register
};

/*
    Example use:
    Register regDACCON(DACCON);
    regDACCON.write(0x12345678);
    regDACCON.REG2.write(0x43);
*/
class Register {
   public:
    // Constructor with actual register address
    Register(volatile uint32_t *address)
        : regAddress(address),
          REG0(regAddress, 0x000000FF, 0),
          REG1(regAddress, 0x0000FF00, 8),
          REG2(regAddress, 0x00FF0000, 16),
          REG3(regAddress, 0xFF000000, 24) {
#ifdef USE_REGISTERS_META
        meta = nullptr;
#endif
    }

    // Read the whole 32 bits register
    uint32_t read() const { return *regAddress; }

    // Write to the whole 32 bits register
    void write(uint32_t value) { *regAddress = value; }

   private:
    volatile uint32_t *regAddress;  // Actual address of the 32 bits register

   public:
    // Instances of sub-registers for individual byte access
    SubRegister REG0;
    SubRegister REG1;
    SubRegister REG2;
    SubRegister REG3;

#ifdef USE_REGISTERS_META
   public:
    // RegisterMeta for debugging purpose.
    // This is public to allow for easier manipulation of the metadata for testing
    // purposes
    const RegisterMeta *meta;
#endif
};
