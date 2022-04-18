/** D1 mini Shiel - SGP30 Sensor 
 *  
 *  Lib:
 *  https://github.com/adafruit/Adafruit_SGP30
 *  
 *  Created with help of the existing examples
 *  Created by S. Fambach
 *  
 *  Visit https://www.Fambach.net if you want
 *  
 */

#include <Wire.h>
#include <Adafruit_SGP30.h>
Adafruit_SGP30 sensor; 

void setup()
{

  Serial.begin(115200);
  if (sensor.begin() == false)
  {
    Serial.println(F("Sensor not found"));
    while (1)
      ;
  }


}

void loop()
{

  delay(1000);

  if (sensor.IAQmeasure())
  {

    Serial.print("CO2: ");
    Serial.println(sensor.eCO2);

    Serial.print("TVOC: ");
    Serial.println(sensor.TVOC);
  }
  else
  {
    Serial.println(F("Measurement Error!"));
  }   

  
}
