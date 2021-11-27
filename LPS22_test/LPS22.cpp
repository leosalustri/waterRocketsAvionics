#include "LPS22.h"

LPS22::LPS22(){
	
}

int LPS22::setup(){
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_WHO_AM_I);
	Wire1.endTransmission();
	Wire1.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t who = Wire1.read();

  Serial.println(who, HEX);
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_CTRL_REG1);
	Wire1.write(0b01000000);
	Wire1.endTransmission();
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_CTRL_REG1);
	Wire1.write(0b01000000);
	Wire1.write(0b00010000);
	Wire1.endTransmission();

	return who;
}

bool LPS22::tempIsAvailable(){
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_STATUS);
	Wire1.endTransmission();
	Wire1.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t stat = Wire1.read();
	return (stat & 0b00000010)>>1;
}

bool LPS22::pressureIsAvailable(){
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_STATUS);
	Wire1.endTransmission();
	Wire1.requestFrom(LPS22HB_ADDRESS,1);
	uint8_t stat = Wire1.read();
	return (stat & 0b00000001);
}

//da la pressione in millibar o hPa che é lo stesso
float LPS22::getPressure(){
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_PRESS_OUT_XL);
	Wire1.endTransmission();
	Wire1.requestFrom(LPS22HB_ADDRESS,3);
  float reading = ((Wire1.read() | 
			Wire1.read() << 8 |
			Wire1.read() << 16)) / 4096.0;
	/*uint8_t pre[3];
	pre[0] = Wire1.read();
	pre[1] = Wire1.read();
	pre[2] = Wire1.read();
	int32_t re = (((signed char)pre[2]) << 16)
				| (((int) (unsigned char)pre[1]) << 8)
				| (((int) (unsigned char)pre[0]) << 0);
	float reading = re / 4096.0;
  */
	return reading;
}

//da la temperatura in C
float LPS22::getTemp(){
	
	Wire1.beginTransmission(LPS22HB_ADDRESS);
	Wire1.write(LPS22HB_TEMP_OUT_L);
	Wire1.endTransmission();
	Wire1.requestFrom(LPS22HB_ADDRESS,2);
	float reading = (Wire1.read() | 
			Wire1.read() << 8 ) / 100.0;
	return reading;
}
