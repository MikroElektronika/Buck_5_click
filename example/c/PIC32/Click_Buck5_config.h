#include "Click_Buck5_types.h"


const uint32_t _BUCK5_SPI_CFG[ 7 ] =
{ 
        _SPI_MASTER, 
        _SPI_8_BIT, 
        80,
        _SPI_SS_DISABLE, 
        _SPI_DATA_SAMPLE_MIDDLE,
        _SPI_CLK_IDLE_LOW, 
        _SPI_IDLE_2_ACTIVE 
};
