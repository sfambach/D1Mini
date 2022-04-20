/* Testprogramm for D1 motor shields
   Step 1: Motor A Forward -> increase Speed -> decrease speed
   Step 2: Motor B Forward -> increase Speed -> decrease speed
   Step 3: Motor A&B Forward -> increase Speed -> decrease speed

   Lib:
   https://github.com/wemos/LOLIN_I2C_MOTOR_Library

   Inspired by the examples of the library
   Created by S. Fambach
   Visit http://www.fambach.net if you want
*/

#include <Wire.h>

// get the motor lib and get an object

#include "LOLIN_I2C_MOTOR.h"
LOLIN_I2C_MOTOR motor; //I2C address 0x30


void setup()
{

  Wire.begin();
  Serial.begin(115200);
  Serial.println(F("Init Motor Shield..."));

  while (motor.PRODUCT_ID != PRODUCT_ID_I2C_MOTOR) //wait motor shield ready.
  {
    motor.getInfo();
  }
  Serial.println(F("... Success"));

}

void loop()
{

  // M1 forward test ********************************************************
  Serial.print(F("MA forward Test .."));
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
  motor.changeFreq(MOTOR_CH_A, 20000);
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_STOP);

  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_A, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_A, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_A, 0);
  Serial.println(F(".. Finished"));

  // motor.changeStatus(MOTOR_CH_A,MOTOR_STATUS_STOP);


  // M1 backward test ********************************************************
  Serial.print(F("MA Backward Test .."));
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CCW);
  motor.changeFreq(MOTOR_CH_A, 20000);
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_STOP);

  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_A, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_A, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_A, 0);
  Serial.println(F(".. Finished"));
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_STOP);

  
  // M2 forward test ********************************************************
  Serial.print(F("MB forward Test .."));
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CW);
  motor.changeFreq(MOTOR_CH_B, 20000);
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_STOP);

  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_B, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_B, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_B, 0);
  Serial.println(F(".. Finished"));

  // M2 Backward test ********************************************************
  Serial.print(F("MB backward Test .."));
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CCW);
  motor.changeFreq(MOTOR_CH_B, 20000);
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_STOP);

  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_B, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_B, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_B, 0);
  Serial.println(F(".. Finished"));

  // test both motors ********************************************************
  // forward test
  Serial.print(F("Both forward Test .."));
  motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_CW);
  motor.changeFreq(MOTOR_CH_BOTH, 20000);
  //

  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_BOTH, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_BOTH, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_BOTH, 0);
  Serial.println(F(".. Finished"));

  // Backward test ********************************************************
  Serial.print(F("Both backward Test .."));
  motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_CCW);
  motor.changeFreq(MOTOR_CH_BOTH, 20000);


  Serial.print(F(".. increase speed .."));
  for (int i = 0; i < 100; i++) {
    motor.changeDuty(MOTOR_CH_BOTH, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }

  Serial.print(F(".. decrease speed .."));
  for (int i = 100; i > 0; i--) {
    motor.changeDuty(MOTOR_CH_BOTH, i);
    if ( (i % 10) == 0 ) {
      Serial.print(".");
    }
    delay(200);
  }
  motor.changeDuty(MOTOR_CH_BOTH, 0);
  Serial.println(F(".. Finished"));

  /********************************************************/

  motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_STOP);
  delay(2000);
  // stop

}
