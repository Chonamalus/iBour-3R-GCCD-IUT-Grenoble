/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Register Interface 32bits
==========================================================================================

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)
*/

#include "Register32_Interface.h"

/*
    Register class definition
*/
Register::Register(volatile uint32_t *address)
    : regAddress(address),
      REG0(regAddress, 0x000000FF, 0),
      REG1(regAddress, 0x0000FF00, 8),
      REG2(regAddress, 0x00FF0000, 16),
      REG3(regAddress, 0xFF000000, 24) {}

inline uint32_t Register::read() const { return *regAddress; }

inline void Register::write(uint32_t value) { *regAddress = value; }

/*
    The SubRegister class slicing the 32 bits register
*/
inline SubRegister::SubRegister(volatile uint32_t *regAddress, uint32_t mask,
                                uint8_t shift) {
    this->regAddress = regAddress;
    this->mask = mask;
    this->shift = shift;
}

inline uint8_t SubRegister::read() const { return (*regAddress & mask) >> shift; }

inline void SubRegister::write(uint8_t value) {
    *regAddress = (*regAddress & ~mask) | ((value << shift) & mask);
}
