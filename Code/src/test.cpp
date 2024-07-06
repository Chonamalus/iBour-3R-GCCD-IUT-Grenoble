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

// Define a mock memory space for testing
volatile uint32_t mockMemory[10] = {0};

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

#ifdef USE_REGISTERS_META
void testMetadataHandling() {
    Register reg(&mockMemory[2]);

    // Write to the whole 32 bits register
    RegisterMeta meta = RegisterMetaBuilder()
                            .setAddress(0x40000000)
                            .setAccessType(READ_WRITE)
                            .setDefaultValue(0xFFFFFFFF)
                            .setSize(32)
                            .build();

    reg.setMetadata(&meta);
    const RegisterMeta* retrievedMeta = reg.getMetadata();

    if (retrievedMeta != nullptr && retrievedMeta->address == 0x40000000 &&
        retrievedMeta->accessType == READ_WRITE &&
        retrievedMeta->defaultValue == 0xFFFFFFFF && retrievedMeta->size == 32) {
        std::cout << "Metadata Handling Test Passed!" << std::endl;
    } else {
        std::cout << "Metadata Handling Test Failed!" << std::endl;
    }
}
#endif

int main() {
    // This will be my main function for the moment, I don't want to create a main.cpp
    // file yet. This one will just contain the test fonctions here

    testRegisterReadWrite();
    testSubRegisterReadWrite();
#ifdef USE_REGISTERS_META
    testMetadataHandling();
#endif

    return 0;
}