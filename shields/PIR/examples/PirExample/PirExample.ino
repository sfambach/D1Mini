/**
   Example for pir sensor

   Written by S. Famach GPL2
   Visit https://www.fambach.net
*/

// keeps the output 5 seconds on
#define OUTPUT_ON_TIME_S 5

// output pin +
// pin where the pir is connected
#if defined(ESP8266) // d1 mini
#pragma message("ESP8266 Remove Shield while start!")
#define PIR_PIN D3
#define OUTPUT_PIN 2

#elif defined ( ESP32 ) // d1 mini esp32
#if CONFIG_IDF_TARGET_ESP32C3 // c3
#pragma message("ESP32C3")
#define PIR_PIN 7
#define OUTPUT_PIN -1 // build in led is pin 7 ;)

#elif CONFIG_IDF_TARGET_ESP32S2
#pragma message("ESP32S2")
#define PIR_PIN 18
#define OUTPUT_PIN 2

#else
#pragma message("ESP32")
#define PIR_PIN 17
#define OUTPUT_PIN 2

#endif
#else
#error "Unknown board"
#define PIR_PIN -1
#define OUTPUT_PIN -1

#endif

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
  delay(2000);
  Serial.println(F("Started"));
}

long timestamp = millis();
boolean swon = false;
boolean rec = false;


void loop() {

  // check pir pin
  if (digitalRead(PIR_PIN)) {
    
    timestamp = millis(); // refresh timestamp
    if (!swon) {
      Serial.println(F("Switch LED on"));
      digitalWrite(OUTPUT_PIN, HIGH);
      swon = true;
      
    }

    if(!rec){
      rec = true;
      Serial.print(F("Pir is on ..."));
    }
  } else {

    // switch off light if timeout is over
    if ( (millis() - timestamp ) > (OUTPUT_ON_TIME_S * 1000) && swon) {
      Serial.println(F("Switch LED OFF"));
      digitalWrite(OUTPUT_PIN, LOW);
      swon = false;
    }

    if(rec){
      rec = false;
      Serial.println(F("... off"));
    }
  }
}
