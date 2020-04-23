#include <ArduinoOSC.h>

#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!
#include <Preferences.h>

extern "C" {
#include "crypto/base64.h"
}


OscWiFi osc;

Adafruit_LSM9DS1 lsm;
Preferences preferences;

void setupWIFI();

String host = "192.168.1.1";

String base64decode(const String &name);

void configMode(const String &ssid);

const int recv_port = 10000;
const int send_port = 12000;


void initGyro() {

    Serial.println("LSM9DS1 init");

    lsm = Adafruit_LSM9DS1();

    if (!lsm.begin()) {
        Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
        while (1);
    }
    Serial.println("Found LSM9DS1 9DOF");

    lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
    lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
    lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
}


void onOscReceived(OscMessage& m)
{
    Serial.print("callback : ");
    Serial.print(m.ip()); Serial.print(" ");
    Serial.print(m.port()); Serial.print(" ");
    Serial.print(m.size()); Serial.print(" ");
    Serial.print(m.address()); Serial.print(" ");
    Serial.print(m.arg<int>(0)); Serial.print(" ");
    Serial.print(m.arg<float>(1)); Serial.print(" ");
    Serial.print(m.arg<String>(2)); Serial.println();
}

void setup()
{
    Serial.begin(115200);
    setupWIFI();

    Wire.begin(32, 33);

    initGyro();

    osc.begin(recv_port);

    osc.subscribe("/lambda", [](OscMessage& m)
    {
        Serial.print("lambda : ");
        Serial.print(m.ip()); Serial.print(" ");
        Serial.print(m.port()); Serial.print(" ");
        Serial.print(m.size()); Serial.print(" ");
        Serial.print(m.address()); Serial.print(" ");
        Serial.print(m.arg<int>(0)); Serial.print(" ");
        Serial.print(m.arg<float>(1)); Serial.print(" ");
        Serial.print(m.arg<String>(2)); Serial.println();
    });
    osc.subscribe("/wildcard/*/test", [](OscMessage& m)
    {
        Serial.print("wildcard : ");
        Serial.print(m.ip()); Serial.print(" ");
        Serial.print(m.port()); Serial.print(" ");
        Serial.print(m.size()); Serial.print(" ");
        Serial.print(m.address()); Serial.print(" ");
        Serial.print(m.arg<int>(0)); Serial.println();

    });
    osc.subscribe("/sethost", [](OscMessage& m)
    {
        Serial.print(m.address()); Serial.print(" ");
        Serial.print("new host:"); Serial.print(" ");
        Serial.print(m.ip()); Serial.print(" ");
        Serial.println();

        host = m.ip();
    });
    osc.subscribe("/resetconfig", [](OscMessage& m)
    {
        preferences.begin("dings01", false);
        preferences.clear();
        preferences.end();
        Serial.println("Configuration reset");
    });
    osc.subscribe("/restart", [](OscMessage& m)
    {
        Serial.println("Restarting..");
        ESP.restart();
    });
    osc.subscribe("/need/reply", [](OscMessage& m)
    {
        Serial.println("/need/reply");

        int i = 12;
        float f = 34.56F;
        double d = 78.987;
        String s = "hello";
        bool b = true;


        Serial.print("host: "); Serial.print(" ");
        Serial.print(host); Serial.print(" ");
        Serial.println();

        osc.send(host, send_port, "/send", i, f, d, s, b);
    });

}


void setupWIFI() {

    delay(1000);

    preferences.begin("dings01", false);
    String name = preferences.getString("name", String("not set"));
    String ssid = preferences.getString("ssid", String("not set"));
    String pwd = preferences.getString("pwd", String("not set"));
    preferences.end();

    Serial.print("name="); Serial.print(name); Serial.print(" , ");
    Serial.print("ssid="); Serial.print(ssid); Serial.print(" , ");
    Serial.print("pwd="); Serial.print("******"); Serial.print(" , ");
    Serial.print("rport=");Serial.print(preferences.getInt("rport", -1)); Serial.print(" , ");
    Serial.print("sport=");Serial.print(preferences.getInt("sport", -1)); Serial.print(" , ");

    Serial.print("Connecting to WiFi. ssid="); Serial.println(ssid);

    WiFi.begin(
            ssid.c_str(),
            pwd.c_str()
            );
    // WiFi.config(ip, gateway, subnet);
    int timeout = 0;
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
        timeout++;
        if( timeout > 10) {
            configMode(ssid);
        }
    }

    Serial.print("Connecting to WiFi. IP="); Serial.println(WiFi.localIP());

    if (!MDNS.begin(name.c_str())) {
        Serial.println("Unable to set up MSDN");
        while(1) {
            delay(1000);
        }
    }

    Serial.print("MSDN setup OK. name="); Serial.print(name); Serial.println(".local");
}

void configMode(const String &ssid) {
    Serial.print("Unable to connect to wifi. SSID =");
    Serial.println(ssid);
    Serial.println("Entering configuration mode");

    String apssid = "dings01_" + String(random(999));
    Serial.println("Setting up AP with SSID="+apssid);
    WiFi.softAP(apssid.c_str());
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    Serial.println("AP setup complete");
    osc.begin(recv_port);

    osc.subscribe("/ping", [](OscMessage& m)
    {
        Serial.print(m.ip()); Serial.print(" ");
        Serial.print(m.port()); Serial.print(" ");
        Serial.print(m.size()); Serial.print(" ");
        Serial.print(m.address()); Serial.print(" ");
        Serial.println();

        osc.send(m.ip(), send_port, "/ack");
    });

    osc.subscribe("/restart", [](OscMessage& m)
    {
        Serial.println("Restarting..");
        ESP.restart();
    });

    osc.subscribe("/setconfig", [](OscMessage& m)
    {
        Serial.print("setconfig : ");

        String name = m.arg<String>(0);
        String ssid = m.arg<String>(1);
        String pwd = m.arg<String>(2);
        int rport = m.arg<int>(3);
        int sport = m.arg<int>(4);

        Serial.print("name=");Serial.print(name); Serial.print(" , ");
        Serial.print("ssid=");Serial.print(ssid); Serial.print(" , ");
        Serial.print("pwd=");Serial.print(pwd); Serial.print(" , ");
        Serial.print("rport=");Serial.print(rport); Serial.print(" , ");
        Serial.print("sport=");Serial.print(sport); Serial.print(" , ");
        Serial.println();

        preferences.begin("dings01", false);
        preferences.clear();
        preferences.putString("name", base64decode(name));
        preferences.putString("ssid", base64decode(ssid));
        preferences.putString("pwd", base64decode(pwd));
        preferences.putInt("rport", rport);
        preferences.putInt("sport", sport);

        Serial.print("Preferences : ");
        Serial.print("name=");Serial.print(preferences.getString("name", String("not set"))); Serial.print(" , ");
        Serial.print("ssid=");Serial.print(preferences.getString("ssid", String("not set"))); Serial.print(" , ");
        Serial.print("pwd=");Serial.print(preferences.getString("pwd", String("not set"))); Serial.print(" , ");
        Serial.print("rport=");Serial.print(preferences.getInt("rport", -1)); Serial.print(" , ");
        Serial.print("sport=");Serial.print(preferences.getInt("sport", -1)); Serial.print(" , ");
        Serial.println();


        preferences.end();

        osc.send(m.ip(), send_port, "/setconfigerr", 0);
    });


    while( true) {
        delay(10);
        osc.parse(); // should be called
    }
}

String base64decode(const String &name) {
    const char * toDecode = name.c_str();

    size_t outputLength;
    unsigned char * decoded = base64_decode((const unsigned char *)toDecode, strlen(toDecode), &outputLength);

    String tempstring = reinterpret_cast<const char*>(decoded);
    return tempstring;
}


void loop()
{
    osc.parse();

    lsm.read();  /* ask it to read in the data */

    /* Get a new sensor event */
    sensors_event_t a, m, g, temp;

    lsm.getEvent(&a, &m, &g, &temp);

//    debugGyro(a, m, g);


    osc.send(host, send_port, "/gyro",
            a.acceleration.x,
            a.acceleration.y,
            a.acceleration.z,
            m.magnetic.x,
            m.magnetic.y,
            m.magnetic.z,
            g.gyro.x,
            g.gyro.y,
            g.gyro.z);

}

void debugGyro(const sensors_event_t &a, const sensors_event_t &m, const sensors_event_t &g) {
    Serial.print("Accel X: ");
    Serial.print(a.acceleration.x);
    Serial.print(" m/s^2");
    Serial.print("\tY: ");
    Serial.print(a.acceleration.y);
    Serial.print(" m/s^2 ");
    Serial.print("\tZ: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2 ");

    Serial.print("Mag X: ");
    Serial.print(m.magnetic.x);
    Serial.print(" uT");
    Serial.print("\tY: ");
    Serial.print(m.magnetic.y);
    Serial.print(" uT");
    Serial.print("\tZ: ");
    Serial.print(m.magnetic.z);
    Serial.println(" uT");

    Serial.print("Gyro X: ");
    Serial.print(g.gyro.x);
    Serial.print(" rad/s");
    Serial.print("\tY: ");
    Serial.print(g.gyro.y);
    Serial.print(" rad/s");
    Serial.print("\tZ: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");
}

