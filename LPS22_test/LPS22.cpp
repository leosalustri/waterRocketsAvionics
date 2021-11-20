#include "LPS22.h"

LPS22::LPS22(){
	
}

int LPS22::setup(){
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_WHO_AM_I);
	Wire.endTransmission();
	Wire.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t who = Wire.read();
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_CTRL_REG1);
	Wire.write(0b01000000);
	Wire.endTransmission();
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_CTRL_REG1);
	Wire.write(0b01000000);
	Wire.write(0b00010000);
	Wire.endTransmission();

	return who;
}

bool LPS22::tempIsAvailable(){
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_STATUS);
	Wire.endTransmission();
	Wire.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t stat = Wire.read();
	return (stat & 0b00000010)>>1;
}

bool LPS22::pressureIsAvailable(){
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_STATUS);
	Wire.endTransmission();
	Wire.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t stat = Wire.read();
	return (stat & 0b00000001);
}

//da la pressione in millibar o hPa che é lo stesso
int32_t LPS22::getPressure(){
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_PRESS_OUT_XL);
	Wire.endTransmission();
	Wire.requestFrom(LPS22HB_ADDRESS,3);
	/* float reading = ((Wire.read() | 
			Wire.read() << 8 |
			Wire.read() << 16) / 4096.0; */
	uint8_t pre[3];
	pre[0] = Wire.read();
	pre[1] = Wire.read();
	pre[2] = Wire.read();
	int32_t re = (((signed char)pre[2]) << 16)
				| (((int) (unsigned char)pre[1]) << 8)
				| (((int) (unsigned char)pre[0]) << 0);
	float reading = re / 4096.0;
	return re;
}

//da la temperatura in C
float LPS22::getTemp(){
	
	Wire.beginTransmission(LPS22HB_ADDRESS);
	Wire.write(LPS22HB_TEMP_OUT_L);
	Wire.endTransmission();
	Wire.requestFrom(LPS22HB_ADDRESS,2);
	float reading = (Wire.read() | 
			Wire.read() << 8 ) / 100.0;
	return reading;
}