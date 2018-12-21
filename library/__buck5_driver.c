/*
    __buck5_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__buck5_driver.h"
#include "__buck5_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t BUCK5_VOLTAGE_1000mV  = 0x00;
const uint8_t BUCK5_VOLTAGE_1500mV  = 0x11;
const uint8_t BUCK5_VOLTAGE_2000mV  = 0x24;
const uint8_t BUCK5_VOLTAGE_2500mV  = 0x39;
const uint8_t BUCK5_VOLTAGE_3000mV  = 0x50;
const uint8_t BUCK5_VOLTAGE_3500mV  = 0x6E;
const uint8_t BUCK5_VOLTAGE_4000mV  = 0x8C;
const uint8_t BUCK5_VOLTAGE_4500mV  = 0xB7;
const uint8_t BUCK5_VOLTAGE_5000mV  = 0xE1;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __BUCK5_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __BUCK5_DRV_SPI__

void buck5_spiDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
}

#endif
#ifdef   __BUCK5_DRV_I2C__

void buck5_i2cDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __BUCK5_DRV_UART__

void buck5_uartDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */


void buck5_powerOn()
{
    hal_gpio_anSet(1);
}


void buck5_reset()
{
   hal_gpio_rstSet(1);
   Delay_10ms();
   hal_gpio_rstSet(0);
   Delay_100ms();
   Delay_100ms();
   hal_gpio_rstSet(1);
   Delay_100ms();
}

void buck5_setOutputVoltage(uint8_t voltage)
{
    uint8_t writeReg[4];
    writeReg[ 0 ] = 0x00;
    writeReg[ 1 ] = voltage;
    writeReg[ 2 ] = 0x20;
    writeReg[ 3 ] = voltage;
    
    hal_gpio_csSet(0);
    hal_spiWrite(writeReg,4);
    hal_gpio_csSet(1);
}








/* -------------------------------------------------------------------------- */
/*
  __buck5_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */