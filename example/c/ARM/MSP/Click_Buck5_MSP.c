/*
Example for Buck5 Click

    Date          : Feb 2018.
    Author        : MikroE Team

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization -  Initializes SPI module and AN pin, RST pin, CS pin as OUTPUT and PWM pin as INPUT
- Application Initialization - Initializes driver init, power On chip and reset buck 5 click
- Application Task - (code snippet) - Sets 3 different output voltages every 2 seconds.

*/

#include "Click_Buck5_types.h"
#include "Click_Buck5_config.h"

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );  
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_BUCK5_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );

    Delay_ms( 100 );
}

void applicationInit()
{
    buck5_spiDriverInit( (T_BUCK5_P)&_MIKROBUS1_GPIO, (T_BUCK5_P)&_MIKROBUS1_SPI );
    buck5_powerOn();
    buck5_reset();
}

void applicationTask()
{
    buck5_setOutputVoltage(BUCK5_VOLTAGE_1500mV);
    Delay_ms( 2000 );
    buck5_setOutputVoltage(BUCK5_VOLTAGE_3000mV);
    Delay_ms( 2000 );
    buck5_setOutputVoltage(BUCK5_VOLTAGE_4500mV);
    Delay_ms( 2000 );
    buck5_setOutputVoltage(BUCK5_VOLTAGE_3000mV);
    Delay_ms( 2000 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}