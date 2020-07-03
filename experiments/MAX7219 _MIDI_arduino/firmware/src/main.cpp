#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 4);  // Pins: DIN,CLK,CS, # of Display connected


void setup() {
    // Serial.begin(115200);
    // delay(1000);
    lc.shutdown(0, false);  // Wake up displays
    lc.shutdown(1, false);
    lc.shutdown(2, false);
    lc.shutdown(3, false);
    lc.setIntensity(0, 5);  // Set intensity levels
    lc.setIntensity(1, 5);
    lc.setIntensity(2, 5);
    lc.setIntensity(3, 5);
    lc.clearDisplay(0);  // Clear Displays
    lc.clearDisplay(1);
    lc.clearDisplay(2);
    lc.clearDisplay(3);

}

void slide(bool state, int delaytime) {
    for (int screen = 0; screen < 4; screen++) {
        for (int col = 0; col < 8; col++) {
            for (int row = 0; row < 8; row++) {
                lc.setLed(screen, row, 7 - col, state);
                if (state) {
                    lc.setIntensity(screen, 8 - col);
                } else {
                    lc.setIntensity(screen, col);
                }
                // delay(delaytime);
            }
        }
    }
}


void loop() {

    slide(true, 0);
    slide(false, 0);

    /*
    for (int screen = 0; screen < 4; screen++) {
        for (int col = 0; col < 8; col++) {
            lc.setColumn(screen, 7 - col, B11111111);
            lc.setIntensity(screen, col);
            // delay(100);
        }
    }


    for (int intensity = 0; intensity < 11; intensity++) {
        for (int screen = 0; screen < 4; screen++) {
            lc.setIntensity(screen, 10 - intensity);
            // delay(20);
        }
    }
    for (int screen = 0; screen < 4; screen++) {
        lc.clearDisplay(screen);  // Clear Displays
        // delay(100);
    }
     */
}

