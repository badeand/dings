
#include "Arduino.h"
#include "MIDIUSB.h"

#define CH_1  2
#define CH_2  3
#define CH_3  4


void setup() {
    Serial.begin(115200);
    pinMode(CH_1, OUTPUT);
    pinMode(CH_2, OUTPUT);
    pinMode(CH_3, OUTPUT);
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

void loop() {

    midiEventPacket_t rx;
    do {
        rx = MidiUSB.read();
        if (rx.header != 0) {
            // debugMIDI(rx);

            if (rx.byte2 == 48 && rx.header == 9) {
                digitalWrite(CH_1, true);
                delay(5);
                digitalWrite(CH_1, false);
            }

            if (rx.byte2 == 49 && rx.header == 9) {
                digitalWrite(CH_2, true);
                delay(5);
                digitalWrite(CH_2, false);
            }

            if (rx.byte2 == 50 && rx.header == 9) {
                digitalWrite(CH_3, true);
                delay(5);
                digitalWrite(CH_3, false);
            }


        }
    } while (rx.header != 0);


}

