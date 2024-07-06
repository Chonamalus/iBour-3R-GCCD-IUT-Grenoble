/*
===============================================
ADuC7061 Microprocessor Register Definitions
===============================================

TO-DO: found the UART right register addresses

Changelog:
-- Version 0.1.7 Chonamalus
    -- Architecture modification on addresses
-- Version 0.1.6 Keil
    -- Initial file founded on Keil's website

Source:
    https://www.keil.com/dd/docs/arm/adi/aduc7061.h

Description:
    This header file provides definitions for the registers of the ADuC7061
microprocessor, an ARM7TDMI-based microcontroller, as described in the datasheet. It
allows direct access to the microprocessor's memory-mapped registers for various
functionalities such as interrupt control, system control, timers, PLL and oscillator
control, ADC and DAC interface, UART, I2C bus, SPI, GPIO, Flash control, and PWM.

Programming techniques and optimization:
    1. Volatile Keyword: The volatile keyword ensures that the compiler does not optimize
away the access to the register, which is important for memory-mapped I/O.
*/

#pragma once
#include <stdint.h>

// INTERRUPT CONTROLLER
#define IRQSTA (*(volatile uint32_t *)0xFFFF0000)
#define IRQSIG (*(volatile uint32_t *)0xFFFF0004)
#define IRQEN (*(volatile uint32_t *)0xFFFF0008)
#define IRQCLR (*(volatile uint32_t *)0xFFFF000C)
#define SWICFG (*(volatile uint32_t *)0xFFFF0010)
#define IRQBASE (*(volatile uint32_t *)0xFFFF0014)
#define IRQVEC (*(volatile uint32_t *)0xFFFF001C)
#define IRQP0 (*(volatile uint32_t *)0xFFFF0020)
#define IRQP1 (*(volatile uint32_t *)0xFFFF0024)
#define IRQP2 (*(volatile uint32_t *)0xFFFF0028)
#define IRQCONN (*(volatile uint32_t *)0xFFFF0030)
#define IRQCONE (*(volatile uint32_t *)0xFFFF0034)
#define IRQCLRE (*(volatile uint32_t *)0xFFFF0038)
#define IRQSTAN (*(volatile uint32_t *)0xFFFF003C)
#define FIQSTA (*(volatile uint32_t *)0xFFFF0100)
#define FIQSIG (*(volatile uint32_t *)0xFFFF0104)
#define FIQEN (*(volatile uint32_t *)0xFFFF0108)
#define FIQCLR (*(volatile uint32_t *)0xFFFF010C)
#define FIQVEC (*(volatile uint32_t *)0xFFFF011C)
#define FIQSTAN (*(volatile uint32_t *)0xFFFF013C)

// REMAP AND SYSTEM CONTROL
#define REMAP (*(volatile uint32_t *)0xFFFF0220)
#define RSTSTA (*(volatile uint32_t *)0xFFFF0230)
#define RSTCLR (*(volatile uint32_t *)0xFFFF0234)

// TIMER 0
#define T0LD (*(volatile uint32_t *)0xFFFF0320)
#define T0VAL (*(volatile uint32_t *)0xFFFF0324)
#define T0CON (*(volatile uint32_t *)0xFFFF0328)
#define T0CLRI (*(volatile uint32_t *)0xFFFF032C)
#define T0CAP (*(volatile uint32_t *)0xFFFF0330)

// WAKE UP TIMER
#define T1LD (*(volatile uint32_t *)0xFFFF0340)
#define T1VAL (*(volatile uint32_t *)0xFFFF0344)
#define T1CON (*(volatile uint32_t *)0xFFFF0348)
#define T1CLRI (*(volatile uint32_t *)0xFFFF034C)

// WATCHDOG TIMER
#define T2LD (*(volatile uint32_t *)0xFFFF0360)
#define T2VAL (*(volatile uint32_t *)0xFFFF0364)
#define T2CON (*(volatile uint32_t *)0xFFFF0368)
#define T2CLRI (*(volatile uint32_t *)0xFFFF036C)

// TIMER 3
#define T3LD (*(volatile uint32_t *)0xFFFF0380)
#define T3VAL (*(volatile uint32_t *)0xFFFF0384)
#define T3CON (*(volatile uint32_t *)0xFFFF0388)
#define T3CLRI (*(volatile uint32_t *)0xFFFF038C)
#define T3CAP (*(volatile uint32_t *)0xFFFF0390)

// PLL AND OSCILLATOR CONTROL
#define POWKEY1 (*(volatile uint32_t *)0xFFFF0404)
#define POWCON0 (*(volatile uint32_t *)0xFFFF0408)
#define POWKEY2 (*(volatile uint32_t *)0xFFFF040C)
#define PLLKEY1 (*(volatile uint32_t *)0xFFFF0410)
#define PLLCON (*(volatile uint32_t *)0xFFFF0414)
#define PLLKEY2 (*(volatile uint32_t *)0xFFFF0418)
#define POWKEY3 (*(volatile uint32_t *)0xFFFF0434)
#define POWCON1 (*(volatile uint32_t *)0xFFFF0438)
#define POWKEY4 (*(volatile uint32_t *)0xFFFF043C)
#define GP0KEY1 (*(volatile uint32_t *)0xFFFF0464)
#define GP0CON1 (*(volatile uint32_t *)0xFFFF0468)
#define GP0KEY2 (*(volatile uint32_t *)0xFFFF046C)

// ADC INTERFACE REGISTERS
#define ADCSTA (*(volatile uint32_t *)0xFFFF0500)
#define ADCMSKI (*(volatile uint32_t *)0xFFFF0504)
#define ADCMDE (*(volatile uint32_t *)0xFFFF0508)
#define ADC0CON (*(volatile uint32_t *)0xFFFF050C)
#define ADC1CON (*(volatile uint32_t *)0xFFFF0510)
#define ADCFLT (*(volatile uint32_t *)0xFFFF0514)
#define ADCCFG (*(volatile uint32_t *)0xFFFF0518)
#define ADC0DAT (*(volatile uint32_t *)0xFFFF051C)
#define ADC1DAT (*(volatile uint32_t *)0xFFFF0520)
#define ADC0OF (*(volatile uint32_t *)0xFFFF0524)
#define ADC1OF (*(volatile uint32_t *)0xFFFF0528)
#define ADC0GN (*(volatile uint32_t *)0xFFFF052C)
#define ADC1GN (*(volatile uint32_t *)0xFFFF0530)
#define ADCORCR (*(volatile uint32_t *)0xFFFF0534)
#define ADCORCV (*(volatile uint32_t *)0xFFFF0538)
#define ADCOTH (*(volatile uint32_t *)0xFFFF053C)
#define ADCOTHC (*(volatile uint32_t *)0xFFFF0540)
#define ADCOTHV (*(volatile uint32_t *)0xFFFF0544)
#define ADCOACC (*(volatile uint32_t *)0xFFFF0548)
#define ADCOATH (*(volatile uint32_t *)0xFFFF054C)
#define IEXCON (*(volatile uint32_t *)0xFFFF0570)

// DAC INTERFACE REGISTERS
#define DACCON (*(volatile uint32_t *)0xFFFF0600)
#define DACDAT (*(volatile uint32_t *)0xFFFF0604)

// UART
#define COMTX (*(volatile uint32_t *)0xFFFF0700)
#define COMRX (*(volatile uint32_t *)0xFFFF0700)    // 0xFFFF0701
#define COMDIV0 (*(volatile uint32_t *)0xFFFF0700)  // 0xFFFF0702-3
#define COMIEN0 (*(volatile uint32_t *)0xFFFF0704)
#define COMDIV1 (*(volatile uint32_t *)0xFFFF0704)  // 0xFFFF0706
#define COMIID0 (*(volatile uint32_t *)0xFFFF0708)
#define COMCON0 (*(volatile uint32_t *)0xFFFF070C)
#define COMCON1 (*(volatile uint32_t *)0xFFFF0710)
#define COMSTA0 (*(volatile uint32_t *)0xFFFF0714)
#define COMSTA1 (*(volatile uint32_t *)0xFFFF0718)
#define COMDIV2 (*(volatile uint32_t *)0xFFFF072C)

// I2C BUS PERIPHERAL DEVICE
#define I2CMCON (*(volatile uint32_t *)0xFFFF0900)
#define I2CMSTA (*(volatile uint32_t *)0xFFFF0904)
#define I2CMRX (*(volatile uint32_t *)0xFFFF0908)
#define I2CMTX (*(volatile uint32_t *)0xFFFF090C)
#define I2CMCNT0 (*(volatile uint32_t *)0xFFFF0910)
#define I2CMCNT1 (*(volatile uint32_t *)0xFFFF0914)
#define I2CADR0 (*(volatile uint32_t *)0xFFFF0918)
#define I2CADR1 (*(volatile uint32_t *)0xFFFF091C)
#define I2CDIV (*(volatile uint32_t *)0xFFFF0924)
#define I2CSCON (*(volatile uint32_t *)0xFFFF0928)
#define I2CSSTA (*(volatile uint32_t *)0xFFFF092C)
#define I2CSRX (*(volatile uint32_t *)0xFFFF0930)
#define I2CSTX (*(volatile uint32_t *)0xFFFF0934)
#define I2CALT (*(volatile uint32_t *)0xFFFF0938)
#define I2CID0 (*(volatile uint32_t *)0xFFFF093C)
#define I2CID1 (*(volatile uint32_t *)0xFFFF0940)
#define I2CID2 (*(volatile uint32_t *)0xFFFF0944)
#define I2CID3 (*(volatile uint32_t *)0xFFFF0948)
#define I2CFSTA (*(volatile uint32_t *)0xFFFF094C)

// SERIAL PORT INTERFACE PERIPHERAL
#define SPISTA (*(volatile uint32_t *)0xFFFF0A00)
#define SPIRX (*(volatile uint32_t *)0xFFFF0A04)
#define SPITX (*(volatile uint32_t *)0xFFFF0A08)
#define SPIDIV (*(volatile uint32_t *)0xFFFF0A0C)
#define SPICON (*(volatile uint32_t *)0xFFFF0A10)

// GPIO AND SERIAL PORT MUX
#define GP0CON0 (*(volatile unsigned long *)0xFFFF0D00)
#define GP1CON (*(volatile unsigned long *)0xFFFF0D04)
#define GP2CON (*(volatile unsigned long *)0xFFFF0D08)
#define GP0DAT (*(volatile unsigned long *)0xFFFF0D20)
#define GP0SET (*(volatile unsigned long *)0xFFFF0D24)
#define GP0CLR (*(volatile unsigned long *)0xFFFF0D28)
#define GP0PAR (*(volatile unsigned long *)0xFFFF0D2C)
#define GP1DAT (*(volatile unsigned long *)0xFFFF0D30)
#define GP1SET (*(volatile unsigned long *)0xFFFF0D34)
#define GP1CLR (*(volatile unsigned long *)0xFFFF0D38)
#define GP1PAR (*(volatile unsigned long *)0xFFFF0D3C)
#define GP2DAT (*(volatile unsigned long *)0xFFFF0D40)
#define GP2SET (*(volatile unsigned long *)0xFFFF0D44)
#define GP2CLR (*(volatile unsigned long *)0xFFFF0D48)
#define GP2PAR (*(volatile unsigned long *)0xFFFF0D4C)

// TO-DO: add GPIO, PWM, flash control interface