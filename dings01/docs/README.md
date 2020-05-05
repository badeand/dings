# dings01

Dings01 er en ting jeg har laget for å utforske interaksjon mellom menneske og maskin for å styre musikkinstrumenter.

Dings01 leser av bevegelsene du gjør med den den og oversetter de til kontrollsignaler som kan kan styre digitale musikkinstrumenter og effekter. Et gyroskop måler bevegelsene og vinklene til tingen som oversettes til parametere på en synth eller effekt. Dings01 kan brukes til å skape lydlandskaper og generere melodier.

Løsningen fungerer slik:
- En mikrontroller (ESP32) leser av verdiene på gyroskopet
- mikrokontrolleren har tilkobling til nett via wifi
- OSC brukes (nettverksprotkoll) for å kommunisere mellom maskin og dings
- En max for live device brukes for å kommunisere mellom Ableton Live og tingen
- Man kan velge hvilke måleverdier fra gyroskopet som skal styre hvilke parameterere på i Ableton Live 

![components](./diagrams/components.png)

Dings01 kan kan sende både noter og kontrollsignaler. Man kan velge hvilke avlesninger som skal generere MIDI- noter.

Innstillinger til trådløst nett lagres i minnet på mikrokontrolleren. Det er laget et eget program for å sette innstillinger for trådløst nett. Dersom mikrokontroller ikke får koblet seg til wifi- nett, går den automatisk inn i konfigurasjonsmodus slik at man kan sette korrekte instillinger.

En av hensiktene med dings01 var å eksperimentere med hvor god responstiden fra bevegelse til endring i lyd i Ableton Live  er og og utforske hvilke innstillinger det kan være interessant å styre med et gyroskop.


## Hardware

* Microcontroller: [Geekcreit ESP32 microcontroller](https://www.banggood.com/no/ESP32-Development-Board-WiFibluetooth-Ultra-Low-Power-Consumption-Dual-Cores-ESP-32-ESP-32S-Board-p-1109512.html)
* Gyroscope: [Adafruit LSM9DS1](https://learn.adafruit.com/adafruit-lsm9ds1-accelerometer-plus-gyro-plus-magnetometer-9-dof-breakout)
* Battery: Any plain USB battery pack will do

## Firmware

Firmware for the ESP32 is implemented in C++ using the Arduino platform.

[platformio](https://platformio.org/) was used as development platform.

For sourcecode, see: [main.cpp](../firmware/src/main.cpp)

## Setup

see [setup procedure](../../setup/README.md)

## Max 4 Live device

The device can be downloaded here: [dings01.amxd](../m4l/dings01/dings01.amxd)

![photo3](./screenshots/m4ldevice.png)

## Photos of prototype

![photo1](./images/dings01_photo_1.jpg)


![photo2](./images/dings01_photo_2.jpg)


![photo3](./images/dings01_photo_3.jpg)
