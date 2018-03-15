#include <Arduino.h>
#include <WiFi.h>
#include "connIds.c"

void setup() {
	Serial.begin(115200);
	WiFi.begin(SSID, PSSWD);
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print(".");
		delay(500);
	}
	Serial.printf("connected to %s", SSID);
    // put your setup code here, to run once:
}

void loop() {
    // put your main code here, to run repeatedly:
}
