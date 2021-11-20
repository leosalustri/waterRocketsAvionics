#include "LPS22.h"
#include "Wire.h"

LPS22 baro;

void setup() {

  Wire.begin();
  Serial.begin(9600);
  Serial.println("inizio");
  //Serial.println(baro.setup(),BIN);
  baro.setup();
}

void loop() {
  
  if(baro.tempIsAvailable()){
    //Serial.print("la temperatura e': ");
    //Serial.print(baro.getTemp(),3);
    //Serial.print(" *C , ");
  }

  if(baro.pressureIsAvailable()){
    //Serial.print("la pressione e': ");
    Serial.println(baro.getPressure(),BIN);
    //Serial.println(" mbar");
  }

  delay(3000);

}
