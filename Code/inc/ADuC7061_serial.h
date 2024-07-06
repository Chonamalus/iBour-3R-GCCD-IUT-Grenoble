/*
=====================================================
ADuC7061 Microprocessor - Serial communication (UART)
=====================================================

TO-DO:
    - finish the class and define it well
    - maybe create a class that handle stuff very close to register, and an API class
    - clock definition
    - must found the right register address
    - must send status of serial by serial Write (maybe impossible)


Changelog:
-- Version 0.0.0 Chonamalus
    -- UART communication from registers

Description:
    §§§§
*/

#pragma once
#include <ADuC7061_MMR.h>

class Serial {
  public:
    Serial(long baudrate);
    ~Serial();

    void setBaudrate(long baudrate);
    void getStatus();

    void read(uint8_t byte);
    void read(uint8_t *buffer, size_t size);
    void write(uint8_t byte);
    void write(uint8_t *buffer, size_t size);

  private:
    long baudrate; // maybe not necessary, must be better attribute for division in PLL!!
};