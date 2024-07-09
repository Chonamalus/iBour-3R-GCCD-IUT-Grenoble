#include "UART_Ctrl.h"
/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - UART Control at Device Abstraction Layer
==========================================================================================

TO-DO:
    - revoir les mask a appliqué sur les registres pour que ca marche bien, ne pas faire
confiance au code des professionnels!!!

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    §§§§
*/

#include "UART_Ctrl.h"

inline void UARTCtrl::setBaudRate(const uint16_t baudRate) {
    // Enable access to COMDIV registers, to set Divisor Latch (DL) for baudRate
    COMCON0 = BIT7;

    // Set DL -> baudRate = 10.24MHz/(16*2*DL) (DL in decimal)
    COMDIV1 = 0x00;  // Never really needed here
    if (baudRate == 9600) {
        COMDIV0 = 0x21;
        COMDIV2 = 0x15 + BIT11;  // DL with fractional divider for accuraty
    }
    if (baudRate == 19200) {
        COMDIV0 = 0x10;
        COMDIV2 = 0x55 + BIT11;  // DL with fractional divider for accuraty
    }
    if (baudRate == 115200) {
        COMDIV0 = 0x02;
        COMDIV2 = 0x31C + BIT11;  // DL with fractional divider for accuraty
    }
}

inline void UARTCtrl::setWordLenght(const uint8_t wordLenght) {
    // Set the WLS
    if (wordLenght == 5) {
        COMCON0 &= 0x00 | (!BIT1 + !BIT0) & 0xFF;
    }
    if (wordLenght == 6) {
        COMCON0 &= 0x00 | (!BIT1 + BIT0) & 0xFF;
    }
    if (wordLenght == 7) {
        COMCON0 &= 0x00 | (BIT1 + !BIT0) & 0xFF;
    }
    if (wordLenght == 8) {
        COMCON0 &= 0x00 | (BIT1 + BIT0) & 0xFF;
    }
}

inline void UARTCtrl::enableStopBit(const bool isThereStopBit) {
    if (isThereStopBit) {
        COMCON0 &= 0x00 | (BIT2) & 0xFF;
    }
    if (!isThereStopBit) {
        COMCON0 &= 0x00 | (!BIT2) & 0xFF;
    }
}
