/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register Interface 32bits
==========================================================================================

TO-DO:
    create a Builder Pattern to store the 'metadata' of each registers
    'metadata' : address, access type (READ WRITE), default value, size

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    The Register interface is created to manipulate either the entire 32bits register or
to manipulate each bytes of it, represented by the SubRegisters. It is usefull because
sometimes, the entire 32 bits of data in one address isn't used, but just some part of it.
Slicing the memory, makes it simpler to manipulate. It is possible to read and write to
the entire register, or just to its subregisters.
    Contains metadata attributes and members, for debugging purpose, so that I can be sure
in my code that I'm running a clean code

Programming techniques and optimization:
    1. Volatile Keyword: The volatile keyword ensures that the compiler does not optimize
away the access to the register, which is important for memory-mapped I/O.
    2. Inline Functions: The inline keyword suggests to the compiler to expand the
function inline, which eliminates the overhead of function calls.
    3. Preprocessor directive : The USE_REGISTERS_META defined variable ensures that the
code uses metadata of registers only for debugging, not for deployment in the
microprocessor
*/

#pragma once
#include <stdint.h>

#include "Register32_Meta.h"
#include "Register32_MetaBuilder.h"

// Ensures that registers metadata is only used for debugging purpose, not for code deployment in microprocessor
#ifdef DEBUG
#define USE_REGISTERS_META
#endif

/*
    Exemple use:
    Register regDACCON(DACCON);
    regDACCON.write(0x12345678);
    regDACCON.REG2.write(0x43);
*/
class Register {
   public:
    inline Register(
        volatile uint32_t *address);  // Constructor w/ actual register address

    inline uint32_t read() const;       // Read the whole 32 bits register
    inline void write(uint32_t value);  // Write to the whole 32 bits register

#ifdef USE_REGISTERS_META
    // Set & get RegisterMeta /!\ Must change, need test in registers
    void setMetadata(RegisterMeta *meta) { metadata = meta; }
    const RegisterMeta *getMetadata() const { return metadata; }
#endif

   private:
    volatile uint32_t *regAddress;  // Address of the 32 bits register
#ifdef USE_REGISTERS_META
    RegisterMeta *metadata;  // RegisterMeta for debugging purpose
#endif

   public:
    // Instances of sub-registers as public for better accessibility
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
    inline SubRegister(volatile uint32_t *regAddress, uint32_t mask, uint8_t shift);

    inline uint8_t read() const;       // Read the sub-register, byte
    inline void write(uint8_t value);  // Write to the sub-register, byte

   private:
    volatile uint32_t *regAddress;  // Address of the main 32-bit register
    uint32_t mask;                  // Mask for the sub-register
    uint8_t shift;                  // Bit shift for the sub-register
};