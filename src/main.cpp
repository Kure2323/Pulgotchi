#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Pet.hpp>
#include <ButtonHandler.hpp>
#include <App.hpp>


/**
 * SSD1306 SCL goes to ESP32 SCL pin -> D22
 * SSD1306 SDA goes to ESP32 SDA pin -> D21
 */
constexpr uint8_t SCREEN_WIDTH { 128 }; // OLED display width, in pixels
constexpr uint8_t SCREEN_HEIGHT { 64 }; // OLED display height, in pixels
constexpr uint8_t SCREEN_ADDRESS { 0x3C }; // Check the back of the display for address -> Usually 0x03C or 0x03D

/**
 * Buttons
 */
constexpr uint8_t L_BUTTON { 19 };
constexpr uint8_t R_BUTTON { 23 };

//#define A_BUTTON 18 // Not used now (I need more cables ;( )


static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);
static Pet pet;
static ButtonHandler buttonHandler(L_BUTTON, R_BUTTON);

// FLASH -> 4MB
// RAM -> 520KB
void setup() {
  // put your setup code here, to run once:
  constexpr bool isInverted = false;
  
  Serial.begin(115200);
  pinMode(L_BUTTON, INPUT_PULLUP);
  pinMode(R_BUTTON, INPUT_PULLUP);


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

static uint32_t lastUpdate = 0;
void loop() {
  // put your main code here, to run repeatedly:

  // Refresh rate ~20 fps
  if (millis() - lastUpdate >= 50) {
    lastUpdate = millis();
    display.display();
  }
    

  pet.update();
  buttonHandler.update();
}

