/*
  Titre      : Temperature et Humiditer
  Auteur     : Duvalier Tsagmo
  Date       : 09/09/2022
  Description: permet de donner la temperature et l'humiditer d'une piece
  Version    : 0.0.1
*/

#include <Arduino.h>
#include <Adafruit_AHTX0.h>

// Declaration des variables
Adafruit_AHTX0 aht;
const int del = 10000;

void setup()
{
    Serial.begin(9600);
    Serial.println("Adafruit AHT10/AHT20 demo!");

    if (!aht.begin())
    {
        Serial.println("Could not find AHT? Check wiring");
        while (1)
            delay(10);
    }
    Serial.println("AHT10 or AHT20 found");
}

void loop()
{
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp); // populate temp and humidity objects with fresh data
    Serial.print("Temperature: ");
    Serial.print(temp.temperature);
    Serial.println(" degrees C");
    Serial.print("Humidity: ");
    Serial.print(humidity.relative_humidity);
    Serial.println("% rH");

    delay(del);
}