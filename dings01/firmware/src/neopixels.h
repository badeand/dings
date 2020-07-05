#ifndef FIRMWARE_NEOPIXELS_H
#define FIRMWARE_NEOPIXELS_H

#endif //FIRMWARE_NEOPIXELS_H

#define NUM_LEDS 19
#define DATA_PIN 22

CRGB leds[NUM_LEDS];

void allBlack();

void initNeopixels() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void startupSignal() {
    for (int p = 0; p < NUM_LEDS; p++) {
        leds[p] = CRGB::Green;
        FastLED.show();
        delay(10);
    }
    for (int p = 0; p < NUM_LEDS; p++) {
        leds[p] = CRGB::Black;
        FastLED.show();
        delay(10);
    }
}

void setupStepOK(int step) {
    allBlack();
    for (int p = 0; p <= step; p++) {
        leds[p] = CRGB::Green;

    }
    FastLED.show();
}

void wifiSetupStep(int step) {
    allBlack();
    for (int p = 0; p <= step; p++) {
        leds[p] = CRGB::Yellow;

    }
    FastLED.show();
}

void allBlack() {
    for (int p = 0; p < NUM_LEDS; p++) {
        leds[p] = CRGB::Black;
    }
    FastLED.show();
}

void showPixel(int pixelId, const CRGB &crgb) {
    leds[pixelId] = crgb;
    FastLED.show();
}

