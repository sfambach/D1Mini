/**
   Example for Singel RGB
   Show RGB and CMY

   Libs:
   https://github.com/adafruit/Adafruit_NeoPixel

   Written by S. Famach GPL2
   Visit https://www.fambach.net
*/


#define LED_COUNT 7


// output pin +
// pin where the pir is connected
#if defined(ESP8266) // d1 mini
#pragma message("ESP8266 Remove Shield while start!")
#define LED_PIN D2

#elif defined ( ESP32 ) // d1 mini esp32

#if CONFIG_IDF_TARGET_ESP32C3 // c3
#pragma message("ESP32C3")
#define LED_PIN 8

#elif CONFIG_IDF_TARGET_ESP32S2
#pragma message("ESP32S2")
#define LED_PIN 33

#else
#pragma message("ESP32")
#define LED_PIN 21

#endif
#else
#error "Unknown board"
#define LED_PIN -1

#endif


// init adafruits neo pixel
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel ledController = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DEF_COLOR 50
static const uint32_t  COLORS[] = { ledController.Color(150, 0, 0), // red
                                    ledController.Color(0, DEF_COLOR, 0), // green
                                    ledController.Color(0, 0, DEF_COLOR), // blue
                                    ledController.Color(DEF_COLOR, DEF_COLOR, 0), // Yellow
                                    ledController.Color(0, DEF_COLOR, DEF_COLOR), // Cyan
                                    ledController.Color(DEF_COLOR, 0, DEF_COLOR)
                                  }; // magenta

uint8_t COLOR_COUNT = 6;

void setup() {
  Serial.begin(115200);
  ledController.begin();
  Serial.println(F("Started"));
}



void loop() {
  ledController.clear(); // Set all pixel colors to 'off'
  delay(500);


  // set all pixels after another
  for (int j = 0; j < COLOR_COUNT; j++) { // For each pixel...

    // set color of single pixel
    ledController.setPixelColor(0, COLORS[j]);
    ledController.show();   // Send the updated pixel colors to the hardware.

    delay(500);
  }


}
