#include <WiFi.h>
#include <WebServer.h>

#ifndef FIRMWARE_WIFICONFIGMODE_H
#define FIRMWARE_WIFICONFIGMODE_H

#endif //FIRMWARE_WIFICONFIGMODE_H

/* IP Address details */
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

Preferences configPrefences;

String SendHTML() {

    configPrefences.begin("dings01", false);
    String name = configPrefences.getString("name", String("not set"));
    String ssid = configPrefences.getString("ssid", String("not set"));
    String pwd = configPrefences.getString("pwd", String("not set"));
    int32_t rport = configPrefences.getInt("rport", -1);
    int32_t sport = configPrefences.getInt("sport", -1);
    configPrefences.end();

    String html = "<!DOCTYPE html>";
    html += "<html lang=\"en\">";
    html += "<head>";
    html += "<meta charset=\"UTF-8\">";
    html += "<title>dings01 configuration</title>";
    html += "</head>";
    html += "<body>";
    html += "<p>";
    html += "<h1>Configuration data</h1>";
    html += "</p>";
    html += "";
    html += "<form action=\"http://192.168.1.1\" method=\"post\"  >";
    html += "Name of dings:<br>";
    html += "<input type=\"text\" id=\"name\" name=\"name\" value=\"" + name + "\"><br>";
    html += "    ";
    html += "<br>WIFI name (SSID):<br>";
    html += "<input type=\"text\" id=\"ssid\" name=\"ssid\" value=\"" + ssid + "\">";
    html += "    ";
    html += "<br><br>WIFI password:<br>";
    html += "<input type=\"text\" id=\"pwd\" name=\"pwd\" value=\"" + pwd + "\">";
    html += "    ";
    html += "<br><br>OSC receive port (e.g. 10000):<br>";
    html += "<input type=\"text\" id=\"rport\" name=\"rport\" value=\"" + String(rport) + "\">";
    html += "    ";
    html += "<br><br>OSC send port (e.g. 12000):<br>";
    html += "<input type=\"text\" id=\"sport\" name=\"sport\" value=\"" + String(sport) + "\">";
    html += "    ";
    html += "<br><br><br>";
    html += "<input type=\"hidden\" id=\"hiddenfield\" name=\"hiddenfield\" value=\"imhere\">";
    html += "    ";
    html += "<input type=\"submit\" value=\"Submit\" >";
    html += "</form>";
    html += "";
    html += "</body>";
    html += "</html>";

    return html;
}

void handle_OnConnect() {

    // if hiddenfield is set, config data has been sent
    if (server.arg("hiddenfield").equals("imhere")) {
        Serial.println("Recieved form data");

        configPrefences.begin("dings01", false);
        configPrefences.clear();
        configPrefences.putString("name", server.arg("name"));
        configPrefences.putString("ssid", server.arg("ssid"));
        configPrefences.putString("pwd", server.arg("pwd"));
        configPrefences.putInt("rport", server.arg("rport").toInt());
        configPrefences.putInt("sport", server.arg("sport").toInt());

        Serial.print("Preferences : ");
        Serial.print("name=");
        Serial.print(configPrefences.getString("name", String("not set")));
        Serial.print(" , ");
        Serial.print("ssid=");
        Serial.print(configPrefences.getString("ssid", String("not set")));
        Serial.print(" , ");
        Serial.print("pwd=");
        Serial.print(configPrefences.getString("pwd", String("not set")));
        Serial.print(" , ");
        Serial.print("rport=");
        Serial.print(configPrefences.getInt("rport", -1));
        Serial.print(" , ");
        Serial.print("sport=");
        Serial.print(configPrefences.getInt("sport", -1));
        Serial.print(" , ");
        Serial.println();

        configPrefences.end();
        configWrittenSignal();
   } else {
        Serial.println("Did not recieve form data");
    }

    server.send(200, "text/html", SendHTML());
    configServeSignal();
    configSetupStep(4);
}

void handle_NotFound() {
    server.send(404, "text/plain", "Not found");
}

void serve() {
    configSetupStep(0);
    Serial.println("Entering configuration mode");

    String apssid = "dings01_" + String(random(999));
    Serial.println("Setting up AP with SSID=" + apssid);
    // WiFi.softAP(ssid, password);
    configSetupStep(1);
    WiFi.softAP(apssid.c_str());
    configSetupStep(2);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    configSetupStep(3);
    delay(100);
    configSetupStep(4);

    server.on("/", handle_OnConnect);
    server.onNotFound(handle_NotFound);

    server.begin();
    configSetupStep(4);
    Serial.println("HTTP server started");
    Serial.println(
            "Please connect to wifinetwork " + apssid + " and point you browser to: http://" + local_ip.toString());

    while (true) {
        server.handleClient();
    }

}

