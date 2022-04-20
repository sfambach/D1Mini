/*I²C Checker for D1 motor shields
 * Lib:
 * https://github.com/wemos/LOLIN_I2C_MOTOR_Library
 * 
 * Inspired by the examples of the library
 * Created by Ss Fambach
 * Visit http://www.fambach.net if you want
*/

#include <Wire.h>
#include "LOLIN_I2C_MOTOR.h"

void setup()
{

  Wire.begin();
  Serial.begin(115200);

  byte error, address;

  Serial.println("Scanning..");
  for (address = 1; address < 127; address++) //find the I2C MOTOR device
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      LOLIN_I2C_MOTOR motor(address);
      if (motor.getInfo() == 0)
      {

        if (motor.PRODUCT_ID == PRODUCT_ID_I2C_MOTOR)
        {
          Serial.print("0x");
          Serial.print(address, HEX);
          Serial.println("Motor");
          while(1); 
        }
      }
    }
  }
  Serial.println("No Motor found, reset to restart");
}

void loop()
{
   
}
