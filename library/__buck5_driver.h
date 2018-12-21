/*
    __buck5_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __buck5_driver.h
@brief    Buck5 Driver
@mainpage Buck5 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BUCK5
@brief      Buck5 Click Driver
@{

| Global Library Prefix | **BUCK5** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Feb 2018.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BUCK5_H_
#define _BUCK5_H_

/** 
 * @macro T_BUCK5_P
 * @brief Driver Abstract type 
 */
#define T_BUCK5_P    const uint8_t*

/** @defgroup BUCK5_COMPILE Compilation Config */              /** @{ */

   #define   __BUCK5_DRV_SPI__                            /**<     @macro __BUCK5_DRV_SPI__  @brief SPI driver selector */
//  #define   __BUCK5_DRV_I2C__                            /**<     @macro __BUCK5_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BUCK5_DRV_UART__                           /**<     @macro __BUCK5_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BUCK5_VAR Variables */                           /** @{ */

extern const uint8_t BUCK5_VOLTAGE_1000mV;
extern const uint8_t BUCK5_VOLTAGE_1500mV;
extern const uint8_t BUCK5_VOLTAGE_2000mV;
extern const uint8_t BUCK5_VOLTAGE_2500mV;
extern const uint8_t BUCK5_VOLTAGE_3000mV;
extern const uint8_t BUCK5_VOLTAGE_3500mV;
extern const uint8_t BUCK5_VOLTAGE_4000mV;
extern const uint8_t BUCK5_VOLTAGE_4500mV;
extern const uint8_t BUCK5_VOLTAGE_5000mV;

                                                                       /** @} */
/** @defgroup BUCK5_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BUCK5_INIT Driver Initialization */              /** @{ */

#ifdef   __BUCK5_DRV_SPI__
void buck5_spiDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P spiObj);
#endif
#ifdef   __BUCK5_DRV_I2C__
void buck5_i2cDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P i2cObj, uint8_t slave);
#endif
#ifdef   __BUCK5_DRV_UART__
void buck5_uartDriverInit(T_BUCK5_P gpioObj, T_BUCK5_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void buck5_gpioDriverInit(T_BUCK5_P gpioObj);
                                                                       /** @} */
/** @defgroup BUCK5_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for power ON chip
 */
void buck5_powerOn();

/**
 * @brief Functions for reset chip
 */
void buck5_reset();

/**
 * @brief Functions for settings maximum output voltage
 *
 * @param[in] voltage    maximum output voltages to be sets
 *
 * Maximum output voltage is 5.5V (255 set value), and minimum output voltage is 1V (0 set value).
 */
void buck5_setOutputVoltage(uint8_t voltage);





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Buck5_STM.c
    @example Click_Buck5_TIVA.c
    @example Click_Buck5_CEC.c
    @example Click_Buck5_KINETIS.c
    @example Click_Buck5_MSP.c
    @example Click_Buck5_PIC.c
    @example Click_Buck5_PIC32.c
    @example Click_Buck5_DSPIC.c
    @example Click_Buck5_AVR.c
    @example Click_Buck5_FT90x.c
    @example Click_Buck5_STM.mbas
    @example Click_Buck5_TIVA.mbas
    @example Click_Buck5_CEC.mbas
    @example Click_Buck5_KINETIS.mbas
    @example Click_Buck5_MSP.mbas
    @example Click_Buck5_PIC.mbas
    @example Click_Buck5_PIC32.mbas
    @example Click_Buck5_DSPIC.mbas
    @example Click_Buck5_AVR.mbas
    @example Click_Buck5_FT90x.mbas
    @example Click_Buck5_STM.mpas
    @example Click_Buck5_TIVA.mpas
    @example Click_Buck5_CEC.mpas
    @example Click_Buck5_KINETIS.mpas
    @example Click_Buck5_MSP.mpas
    @example Click_Buck5_PIC.mpas
    @example Click_Buck5_PIC32.mpas
    @example Click_Buck5_DSPIC.mpas
    @example Click_Buck5_AVR.mpas
    @example Click_Buck5_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __buck5_driver.h

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