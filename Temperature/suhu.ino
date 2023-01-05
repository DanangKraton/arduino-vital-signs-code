#include <Wire.h>
#include "MAX30105.h"
MAX30105 tempSensor;

void setup() {

  Serial.begin(9600);
//  Serial.println("Menginisiasi...");
  Wire.begin();

  //scan for temperature in every 30 sec untill a sensor is found. Scan for both addresses 0x48 and 0x49
  if (!tempSensor.begin(Wire, I2C_SPEED_FAST))
  {
    Serial.println("Couldn't find the temperature sensor, please connect the sensor." );
    while (1);
  }

  tempSensor.begin();   // set continuos mode, active mode
}

void loop() {
  //int readingmax = analogRead();
  //float millivolts = readingmax*(5000/1024);
  //float temperature = millivolts /10;

  float temp = tempSensor.readTemperature(); // read temperature for every 100ms
  float kalibrasi = temp;
  Serial.print(kalibrasi ,2);
  Serial.println("'c" );
  delay(500);
}
