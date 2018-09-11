//Based on Blynk.com code tool. Swapped the problematic Neopixel libary to working FastLed libary. 


#define BLYNK_PRINT Serial
#include <FastLED.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define FASTLED_ALLOW_INTERRUPTS 0

#define noInterrupts() cli()
char auth[] = "AuhtKey;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "PASS";


#define DATA_PIN 18
#define NUM_LEDS 144
CRGB leds[NUM_LEDS];
int R = 0;
int G = 0;
int B = 0;
#define BLYNK_PRINT Serial
  
  
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS); 

  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
  
}


BLYNK_WRITE(V2){
  R = param.asInt();
 

  for(int i=0;i<NUM_LEDS;i++){
    leds[i] =  CRGB(R,G,B);
  
   
}

 FastLED.show();
}

BLYNK_WRITE(V3) {
int G = param.asInt();

 


for(int i=0;i<NUM_LEDS;i++){
    leds[i] =  CRGB(R,G,B);
  }
  
FastLED.show();

}


BLYNK_WRITE(V4){
  B = param.asInt();
  for(int i=0;i<NUM_LEDS;i++){
    leds[i] =  CRGB(R,G,B);
    
}
FastLED.show();
}

void loop()
{
Blynk.run();
}
