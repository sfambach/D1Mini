/** D1 Mini Buzzer Shield Test 
 *  
 *  Tested with 
 *  D1 mini
 *  D1 EP32
 *  
 *  Libraries
 *  only Arduino
 *  
 *  Example based on:
 *  https://github.com/wemos/D1_mini_Examples/tree/master/examples/04.Shields/Buzzer_Shield/Do_Re_Mi
 *  
 *  Enhanced By 
 *  S. Fambach
 *  
 *  Visit https://www.fambach.net if you want
 */
 
#define DUTY 512
#define OFF  0


#ifdef ESP8266
  // nothing to declare
#elif defined(ESP32)
  // define D5 pin for ESP 32
  #ifndef D5
    #define D5 18
  #endif
  
  
  // use first channel of 16 channels (started from zero)
  #define LEDC_CHANNEL_0     0
  
  // use 13 bit precission for LEDC timer
  #define LEDC_TIMER_13_BIT  13
  
  // use 5000 Hz as a LEDC base frequency
  #define LEDC_BASE_FREQ     0

#endif

// define buzzer port 
int buzzer=D5; 

// define Notes
// Note name: C6 D6 E6 F6 G6 A6 B6 C7   
// http://newt.phys.unsw.edu.au/jw/notes.html
int freq[]={1047,1175,1319,1397,1568,1760,1976,2093};

// name notes
String note[]={"C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"};

void setup() {
  
  pinMode(buzzer, OUTPUT);

  
  #if defined( ESP32 )
    // init esp 32 pwm (rest is the same for esp8266 and esp32
    ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
    ledcAttachPin(buzzer, LEDC_CHANNEL_0);
    ledcWrite(LEDC_CHANNEL_0, OFF);
  #endif
  
  digitalWrite(buzzer, LOW);
  
  Serial.begin(115200);
  Serial.println("Buzzer Test...");
}

void loop() {
  for(int i=0; i<8; i++){

// set the current frequency 
#if defined( ESP8266 )
    // we have to set both i don't know why but without this it does not work
    analogWriteRange(freq[i]);
    analogWriteFreq(freq[i]);
#elif defined( ESP32 )
    ledcSetup(LEDC_CHANNEL_0, freq[i], LEDC_TIMER_13_BIT);
    ledcAttachPin(buzzer, LEDC_CHANNEL_0);
#endif

    // write some information on the console about the current note
    Serial.print("Note name: ");
    Serial.print(note[i]);
    Serial.print(", Freq: ");
    Serial.print(freq[i]);
    Serial.println("Hz");

    // turn tone on 
#if defined( ESP8266 )
    pinMode(buzzer, OUTPUT); //?
    analogWrite(buzzer, DUTY);
#elif defined( ESP32 )
    ledcWrite(LEDC_CHANNEL_0, DUTY);
#endif   
    delay(1000);

    // turn tone off 
#if defined( ESP8266 )
    analogWrite(buzzer, OFF);
    digitalWrite(buzzer, LOW);
#elif defined( ESP32 )
    ledcWrite(LEDC_CHANNEL_0, OFF);
#endif 
     
    delay(1000);
  }
  Serial.println("STOP");
  delay(5000);

}
