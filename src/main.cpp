/*
 * I am new to C++ and Hardware programming this is just test code and practice for myself.
 * In this project I have combined a DHT module for humidity & temperatures paired with an LCD module -
 * to display the units.
 *  - Ozark 02/10/2025
 */

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "DHT.h"

/* defining the DHT module type and which pin is connected. ex 4,9,1,A0 etc.
 * Change the DHTPIN to where your module is connected.
 */
#define DHTTYPE DHT11
#define DHTPIN 3

// setup for the dht module.
DHT dht(DHTPIN, DHTTYPE);

// Init Library
LiquidCrystal lcd(7,8,9,10,11,12);
void setup() {
//

    lcd.begin(16, 2);
    lcd.print("Temp");

    lcd.setCursor(7, 0);
    lcd.print("Humidity" );

    // starts the DHT module
    dht.begin();

}

// sets humidity percentage under the humidity text.
void Humidity(float h) {
    lcd.setCursor(7, 1);
    lcd.print("%"); lcd.print(h);
}

void loop() {

    delay(2100);

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    Humidity(h);

    // turns temp from Celsius to Freedom units.
    float f = (t * 1.8f) + 32.f;

    // I found the function below after I wrote the formula above. ^^
    //float f = dht.convertCtoF(t);
    lcd.setCursor(0, 1);
    lcd.print(f); lcd.print("F");

}