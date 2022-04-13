/** D1 Mini Battery Shield Test 
 *  
 *  I do not know if the calculations are correct please check yourself ;)
 *  
 *  Tested with 
 *  D1 mini
 *  D1 EP32
 *  
 *  Libraries
 *  only Arduino
 *  
 *  Created By 
 *  S. Fambach
 *  
 *  Visit https://www.fambach.net if you want
 */

#ifdef ESP8266
  // nothing to declare
#elif defined(ESP32)
  #include <ESP32AnalogRead.h>
  ESP32AnalogRead adc;

  // define D5 pin for ESP 32
  #ifndef A0
    #define A0 36
  #endif

#endif 

void setup() {
    
    Serial.begin(115200);
   
    // init adc
    #ifdef ESP8266
  
    #elif defined(ESP32)
      adc.attach(A0);
    #endif 
  

}

void loop() {

  double voltage = 0.0;
  // read 
  #ifdef ESP8266
    voltage = analogRead(A0);
    // map to voltage   
    voltage = (voltage/1024) + ((4.0 / 420.0 )* 320.0);
  #elif defined(ESP32)
    voltage = adc.readVoltage();
  #endif 
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println("V");
  
}
