#ifndef LPS22_H
#define LPS22_H

#include <Wire.h>

#define LPS22HB_ADDRESS  0x5D  //mi sa che é ox5C per il sensore integrato nel nano 33 

#define LPS22HB_I2C_ADD_H   0xBBU
#define LPS22HB_I2C_ADD_L   0xB9U
#define LPS22HB_THS_P_L        0x0CU
#define LPS22HB_THS_P_H        0x0DU
#define LPS22HB_WHO_AM_I       0x0FU
#define LPS22HB_CTRL_REG1      0x10U
#define LPS22HB_CTRL_REG2      0x11U
#define LPS22HB_CTRL_REG3      0x12U

#define LPS22HB_REF_P_XL       0x15U
#define LPS22HB_REF_P_L        0x16U
#define LPS22HB_REF_P_H        0x17U
#define LPS22HB_RPDS_L         0x18U
#define LPS22HB_RPDS_H         0x19U

#define LPS22HB_RES_CONF       0x1AU

#define LPS22HB_STATUS         0x27U

#define LPS22HB_PRESS_OUT_XL   0x28U
#define LPS22HB_PRESS_OUT_L    0x29U
#define LPS22HB_PRESS_OUT_H    0x2AU
#define LPS22HB_TEMP_OUT_L     0x2BU
#define LPS22HB_TEMP_OUT_H     0x2CU
#define LPS22HB_LPFP_RES       0x33U

class LPS22
{
	
	public:
		LPS22();
		int setup();
		float getTemp();
		int32_t getPressure();
		bool tempIsAvailable();
		bool pressureIsAvailable();
		
	private:
		
};


#endif