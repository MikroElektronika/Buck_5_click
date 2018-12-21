![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Buck5 Click

- **CIC Prefix**  : BUCK5
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : Feb 2018.

---

### Software Support

We provide a library for the Buck5 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2358/buck-5-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Initializes and defines SPI driver and driver functions witch can use for power supply control.
This library offers a choice to set maximum output voltage, witch can be between 1V and 5.5V.
For more details check documentation.

Key functions :

- ``` void buck5_powerOn() ``` - Function for power ON chip.
- ``` void buck5_reset() ``` - Function for reset chip.
- ``` void buck5_setOutputVoltage(uint8_t voltage) ``` - Function for setting maximum output voltage.

**Examples Description**

The application is composed of three sections :

- System Initialization -  Initializes SPI module and AN pin, RST pin, CS pin as OUTPUT and PWM pin as INPUT.
- Application Initialization - Initializes driver init, power On chip and reset Buck 5 click.
- Application Task - (code snippet) - Sets 3 different output voltage every 2 seconds.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2358/buck-5-click) page.

Other mikroE Libraries used in the example:

- Conversions
- SPI
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
