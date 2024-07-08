/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Test file
==========================================================================================

TO-DO:
    §§§§

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    §§§§
*/

#include "config.h"
#ifdef TESTER
#include <iostream>

#include "Register32_Interface.h"
#include "Register32_Meta.h"
#include "Register32_MetaBuilder.h"

// Define a mock memory space for testing
volatile uint32_t mockMemory[10] = {0};

// Test Register Read Write
void testRegisterReadWrite() {
    Register reg(&mockMemory[0]);
    reg.write(0x12345678);
    uint32_t value = reg.read();
    if (value == 0x12345678) {
        std::cout << "Register Read/Write Test Passed!" << std::endl;
    } else {
        std::cout << "Register Read/Write Test Failed! Expected 0x12345678 but got 0x"
                  << std::hex << value << std::endl;
    }
}

// Test SubRegister Read Write
void testSubRegisterReadWrite() {
    Register reg(&mockMemory[1]);
    reg.write(0);  // Clear register

    reg.REG0.write(0x12);
    reg.REG1.write(0x34);
    reg.REG2.write(0x56);
    reg.REG3.write(0x78);

    uint8_t reg0_val = reg.REG0.read();
    uint8_t reg1_val = reg.REG1.read();
    uint8_t reg2_val = reg.REG2.read();
    uint8_t reg3_val = reg.REG3.read();

    if (reg0_val == 0x12 && reg1_val == 0x34 && reg2_val == 0x56 && reg3_val == 0x78) {
        std::cout << "SubRegister Read/Write Test Passed!" << std::endl;
    } else {
        std::cout << "SubRegister Read/Write Test Failed!" << std::endl;
        std::cout << "REG0: Expected 0x12 but got 0x" << std::hex << (int)reg0_val
                  << std::endl;
        std::cout << "REG1: Expected 0x34 but got 0x" << std::hex << (int)reg1_val
                  << std::endl;
        std::cout << "REG2: Expected 0x56 but got 0x" << std::hex << (int)reg2_val
                  << std::endl;
        std::cout << "REG3: Expected 0x78 but got 0x" << std::hex << (int)reg3_val
                  << std::endl;
    }
}

// Test Metadata Handling
#ifdef USE_REGISTERS_META
void testMetadataHandling() {
    Register reg1(&mockMemory[2]);
    Register reg2(&mockMemory[3]);

    // Write to the whole 32 bits register
    RegisterMeta meta1 = RegisterMetaBuilder()
                             .setAccessType(READ_WRITE)
                             .setDefaultValue(0xFFFFFFFF)
                             .setSize(32)
                             .build();

    RegisterMeta meta2 = RegisterMetaBuilder()
                             .setAccessType(READ)
                             .setDefaultValue(0x00000010)
                             .setSize(16)
                             .build();

    // Set the metadata of registers
    reg1.meta = &meta1;
    reg2.meta = &meta2;

    // RegisterMeta Member's tester
    bool isReg1Good = reg1.meta->isReadWrite() &&
                      (reg1.meta->getDefaultValue() == 0xFFFFFFFF) &&
                      reg1.meta->isSize32();
    bool isReg2Good = reg2.meta->isReadable() &&
                      (reg2.meta->getDefaultValue() == 0x00000010) &&
                      reg2.meta->isSize16();

    if (isReg1Good && isReg2Good) {
        std::cout << "Register Metadata Builder Test Passed!" << std::endl;
    } else {
        std::cout << "Register Metadata Builder Test Failed!" << std::endl;
    }
}
#endif

#endif