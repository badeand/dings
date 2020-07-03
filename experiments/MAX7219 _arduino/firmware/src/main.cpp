#include "LedControl.h"
#include "MIDIUSB.h"

LedControl lc = LedControl(7, 8, 9, 4);  // Pins: DIN,CLK,CS, # of Display connected

void debugMIDI(const midiEventPacket_t &rx);

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

void slide(int screen, bool state) {
    for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
            lc.setLed(screen, row, 7 - col, state);
        }
    }
}


void loop() {

    midiEventPacket_t rx;
    do {
        rx = MidiUSB.read();
        if (rx.header != 0) {
            debugMIDI(rx);

            if (rx.byte2 == 48) {
                if (rx.header == 8 ) {
                    slide(0, false);
                }
                if (rx.header == 9 ) {
                    slide(0, true);
                }
            }

            if (rx.byte2 == 49) {
                if (rx.header == 8 ) {
                    slide(1, false);
                }
                if (rx.header == 9 ) {
                    slide(1, true);
                }
            }

            if (rx.byte2 == 50) {
                if (rx.header == 8 ) {
                    slide(2, false);
                }
                if (rx.header == 9 ) {
                    slide(2, true);
                }
            }

            if (rx.byte2 == 51) {
                if (rx.header == 8 ) {
                    slide(3, false);
                }
                if (rx.header == 9 ) {
                    slide(3, true);
                }
            }

            if (rx.byte2 == 7) {
                for (int screen = 0; screen < 4; screen++) {
                    int bri = rx.byte3 / (127 / 15);
                    lc.setIntensity(screen, bri);
                }
            }
        }
    } while (rx.header != 0);
}

void debugMIDI(const midiEventPacket_t &rx) {
    Serial.print("Received: ");
    Serial.print(rx.header, DEC);
    Serial.print("-");
    Serial.print(rx.byte1, DEC);
    Serial.print("-");
    Serial.print(rx.byte2, DEC);
    Serial.print("-");
    Serial.println(rx.byte3, DEC);
}

/*
slide(false, 0);
 */

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

