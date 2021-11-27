#ifndef LPS22_H
#define LPS22_H

#include "Wire.h"

#define LPS22HB_ADDRESS  0x5C  //mi sa che é ox5C per il sensore integrato nel nano 33 

#define LPS22HB_I2C_ADD_H   0xBB
#define LPS22HB_I2C_ADD_L   0xB9
#define LPS22HB_THS_P_L        0x0C
#define LPS22HB_THS_P_H        0x0D
#define LPS22HB_WHO_AM_I       0x0F
#define LPS22HB_CTRL_REG1      0x10
#define LPS22HB_CTRL_REG2      0x11
#define LPS22HB_CTRL_REG3      0x12

#define LPS22HB_REF_P_XL       0x15
#define LPS22HB_REF_P_L        0x16
#define LPS22HB_REF_P_H        0x17
#define LPS22HB_RPDS_L         0x18
#define LPS22HB_RPDS_H         0x19

#define LPS22HB_RES_CONF       0x1A

#define LPS22HB_STATUS         0x27

#define LPS22HB_PRESS_OUT_XL   0x28
#define LPS22HB_PRESS_OUT_L    0x29
#define LPS22HB_PRESS_OUT_H    0x2A
#define LPS22HB_TEMP_OUT_L     0x2B
#define LPS22HB_TEMP_OUT_H     0x2C
#define LPS22HB_LPFP_RES       0x33

class LPS22
{
	
	public:
		LPS22();
		int setup();
		float getTemp();
		float getPressure();
		bool tempIsAvailable();
		bool pressureIsAvailable();
		
	private:
		
};


#endif
