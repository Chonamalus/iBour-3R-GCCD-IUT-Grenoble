/*
===============================================
iBour-3R - Register Interface 32bits
===============================================

TO-DO:
    create a Builder Pattern to store the 'metadata' of each registers
    'metadata' : address, access type (READ WRITE), default value, size

Changelog:
-- Version 0.0.0 Chonamalus
    -- Register interface to simplify development

Description:
    The Register interface is created to manipulate either the entire 32bits register or
to manipulate each bytes of it, represented by the SubRegisters. It is usefull because
sometimes, the entire 32 bits of data in one address isn't used, but just some part of it.
Slicing the memory, makes it simpler to manipulate. It is possible to read and write to
the entire register, or just to its subregisters.

Programming techniques and optimization:
    1. Volatile Keyword: The volatile keyword ensures that the compiler does not optimize
away the access to the register, which is important for memory-mapped I/O.
    2. Inline Functions: The inline keyword suggests to the compiler to expand the
function inline, which eliminates the overhead of function calls.
*/

#pragma once
#include <stdint.h>

/*
    Exemple use:
    Register regDACCON(DACCON);
    regDACCON.write(0x12345678);
    regDACCON.REG2.write(0x43);
*/
class Register {
   public:
    inline Register(volatile uint32_t *address)
        : regAddress(address),
          REG0(regAddress, 0x000000FF, 0),
          REG1(regAddress, 0x0000FF00, 8),
          REG2(regAddress, 0x00FF0000, 16),
          REG3(regAddress, 0xFF000000, 24) {}

    // Read the whole 32 bits register
    inline uint32_t read() const { return *regAddress; }

    // Write to the whole 32 bits register
    inline void write(uint32_t value) { *regAddress = value; }

   private:
    volatile uint32_t *regAddress;  // Address of the 32 bits register

   public:
    // Instances of sub-registers as public to for better accessibility
    SubRegister REG0;
    SubRegister REG1;
    SubRegister REG2;
    SubRegister REG3;
};

/*
    The SubRegister class slicing the 32 bits register
*/
class SubRegister {
   public:
    inline SubRegister(volatile uint32_t *regAddress, uint32_t mask, uint8_t shift) {
        this->regAddress = regAddress;
        this->mask = mask;
        this->shift = shift;
    }

    // Read the sub-register, byte
    inline uint8_t read() const { return (*regAddress & mask) >> shift; }

    // Write to the sub-register, byte
    inline void write(uint8_t value) {
        *regAddress = (*regAddress & ~mask) | ((value << shift) & mask);
    }

   private:
    volatile uint32_t *regAddress;  // Address of the main 32-bit register
    uint32_t mask;                  // Mask for the sub-register
    uint8_t shift;                  // Bit shift for the sub-register
};