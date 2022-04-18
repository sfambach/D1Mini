#include <Wire.h>
#include <Adafruit_SGP30.h>
Adafruit_SGP30 sgp30; 

void setup()
{

  Serial.begin(115200);
  if (sgp30.begin() == false)
  {
    Serial.println(F("Sensor not found"));
    while (1)
      ;
  }


}

void loop()
{

  delay(1000);

  if (sgp30.IAQmeasure())
  {

    Serial.print("CO2: ");
    Serial.println(sgp30.eCO2);

    Serial.print("TVOC: ");
    Serial.println(sgp30.TVOC);
  }
  else
  {
    Serial.println(F("Measurement Error!"));
  }   

  
}
