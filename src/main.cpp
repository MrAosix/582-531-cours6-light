#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>

#define MA_BROCHE_ANGLE 32
#define MA_BROCHE_BOUTON 39
CRGB pixelAtom;

MicroOscSlip<128> monOsc(&Serial);

void setup() {
  Serial.begin(115200);
  pinMode( MA_BROCHE_BOUTON , INPUT );
  FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1);

}

void loop() {
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  //int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );

  if (maLectureAnalogique < 4095 / 3) {
    pixelAtom = CRGB(0,0,255);
  } else if (maLectureAnalogique > 4095 / 3 && maLectureAnalogique < 4095 /3 * 2) {
    pixelAtom = CRGB(0,255,0);
  } else {
    pixelAtom = CRGB(255,0,0);
  }
  FastLED.show();
  //monOsc.sendInt( "/bouton" , maLectureBouton);
  monOsc.sendInt( "/light" , maLectureAnalogique);
  delay(100);

}