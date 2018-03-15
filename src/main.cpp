#include <Arduino.h>
#include <WiFi.h>
#include "connIds.c"
#include <HTTPClient.h>

int i = 0;

void setup()
{
	Serial.begin(115200);
	WiFi.begin(SSID, PSSWD);
	while (WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(500);
	}
	Serial.printf("\nconnected to %s", SSID);
	Serial.print(" with IP : ");
	Serial.print(WiFi.localIP());
}

void loop()
{

	if (WiFi.status() == WL_CONNECTED)
	{
	HTTPClient http;
   http.begin(SERVER_IP);
	 http.addHeader("Content-type", "text/plain");

	int httpResponseCode = http.POST("posting from esp32");

	if (httpResponseCode > 0)
	{
		i++;
		String response = http.getString();

		Serial.printf("\nrequest number %d\n", i);
		Serial.println(httpResponseCode);
		Serial.println(response);
	} else {
		Serial.print("error code : ");
		Serial.println(httpResponseCode);
	}
	http.end();

	} else {
		Serial.print("no wifi connection");
	}
	delay(10000);
}
