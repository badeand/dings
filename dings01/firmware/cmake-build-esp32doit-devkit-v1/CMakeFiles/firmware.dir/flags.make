# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# compile CXX with /Users/badeand/.platformio/packages/toolchain-xtensa32/bin/xtensa-esp32-elf-g++
CXX_FLAGS =  -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.14.sdk   -D'PLATFORMIO=40003' -D'ARDUINO_ESP32_DEV' -D'ESP32' -D'ESP_PLATFORM' -D'F_CPU=240000000L' -D'HAVE_CONFIG_H' -D'MBEDTLS_CONFIG_FILE="mbedtls/esp_config.h"' -D'ARDUINO=10805' -D'ARDUINO_ARCH_ESP32' -D'ARDUINO_VARIANT="doitESP32devkitV1"' -D'ARDUINO_BOARD="DOIT ESP32 DEVKIT V1"' -std=gnu++11

CXX_DEFINES = 

CXX_INCLUDES = -I/Users/badeand/dev/dings/dings01/firmware/include -I/Users/badeand/dev/dings/dings01/firmware/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/Preferences/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/ESPmDNS/src -I"/Users/badeand/dev/dings/dings01/firmware/.pio/libdeps/esp32doit-devkit-v1/Adafruit LSM9DS1 Library_ID4175" -I"/Users/badeand/dev/dings/dings01/firmware/.pio/libdeps/esp32doit-devkit-v1/Adafruit LIS3MDL_ID6931" -I"/Users/badeand/dev/dings/dings01/firmware/.pio/libdeps/esp32doit-devkit-v1/Adafruit Unified Sensor_ID31" -I"/Users/badeand/dev/dings/dings01/firmware/.pio/libdeps/esp32doit-devkit-v1/Adafruit BusIO_ID6214" -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/Wire/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/SPI/src -I/Users/badeand/dev/dings/dings01/firmware/.pio/libdeps/esp32doit-devkit-v1/ArduinoOSC_ID1896 -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/WiFi/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/config -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/app_trace -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/app_update -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/asio -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/bootloader_support -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/bt -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/coap -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/console -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/driver -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp-tls -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp32 -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_adc_cal -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_event -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_http_client -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_http_server -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_https_ota -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp_ringbuf -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/ethernet -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/expat -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/fatfs -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/freemodbus -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/freertos -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/heap -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/idf_test -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/jsmn -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/json -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/libsodium -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/log -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/lwip -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/mbedtls -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/mdns -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/micro-ecc -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/mqtt -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/newlib -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/nghttp -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/nvs_flash -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/openssl -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/protobuf-c -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/protocomm -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/pthread -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/sdmmc -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/smartconfig_ack -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/soc -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/spi_flash -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/spiffs -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/tcp_transport -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/tcpip_adapter -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/ulp -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/vfs -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/wear_levelling -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/wifi_provisioning -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/wpa_supplicant -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/xtensa-debug-module -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp-face -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/esp32-camera -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/tools/sdk/include/fb_gfx -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/cores/esp32 -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/variants/doitESP32devkitV1 -I/Users/badeand/.platformio/lib/PacketSerial_ID1198/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/ArduinoOTA/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/AsyncUDP/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/AzureIoT/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/BLE/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/BluetoothSerial/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/DNSServer/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/EEPROM/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/ESP32/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/FFat/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/FS/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/HTTPClient/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/HTTPUpdate/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/NetBIOS/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/SD/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/SD_MMC/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/SPIFFS/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/SimpleBLE/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/Ticker/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/Update/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/WebServer/src -I/Users/badeand/.platformio/packages/framework-arduinoespressif32/libraries/WiFiClientSecure/src -I/Users/badeand/.platformio/packages/toolchain-xtensa32/xtensa-esp32-elf/include -I/Users/badeand/.platformio/packages/toolchain-xtensa32/xtensa-esp32-elf/include/c++/5.2.0 -I/Users/badeand/.platformio/packages/toolchain-xtensa32/xtensa-esp32-elf/include/c++/5.2.0/xtensa-esp32-elf -I/Users/badeand/.platformio/packages/toolchain-xtensa32/lib/gcc/xtensa-esp32-elf/5.2.0/include -I/Users/badeand/.platformio/packages/toolchain-xtensa32/lib/gcc/xtensa-esp32-elf/5.2.0/include-fixed -I/Users/badeand/.platformio/packages/tool-unity 

