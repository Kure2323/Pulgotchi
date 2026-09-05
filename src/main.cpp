#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include "Pet.hpp"


/**
 * SSD1306 SCL goes to ESP32 SCL pin -> D22
 * SSD1306 SDA goes to ESP32 SDA pin -> D21
 */
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_ADDRESS 0x3C // Check the back of the display for address -> Usually 0x03C or 0x03D

/**
 * Buttons
 */
#define LBUTTON 19
#define RBUTTON 23
#define ABUTTON 18 // Not used now (I need more cables ;( )


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
Pet pulga;

// FLASH -> 4MB
// RAM -> 520KB
void setup() {
  // put your setup code here, to run once:
  const bool isInverted = false;
  
  Serial.begin(115200);
  pinMode(LBUTTON, INPUT_PULLUP);
  pinMode(RBUTTON, INPUT_PULLUP);


  // screen begin
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Error: SSD1306 not found");
    while (true);
  }
  display.clearDisplay();
  display.invertDisplay(isInverted);
  display.drawLine(32, 0, 32, 63, 1);
  display.drawLine(95, 0, 95, 63, 1);
  display.display();
  
}

uint lastUpdate = 0;
void loop() {
  // put your main code here, to run repeatedly:

  // Refresh rate ~20 fps
  if (millis() - lastUpdate >= 50) {
    lastUpdate = millis();
    display.display();
  }
  
  
  
  

  pulga.update();
  display.display();
  delay(5);
}

