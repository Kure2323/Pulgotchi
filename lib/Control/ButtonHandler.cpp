#include <ButtonHandler.hpp>
#include <Arduino.h>


ButtonHandler::ButtonHandler(uint8_t l, uint8_t r) {
    lButton.buttonPin = l;
    rButton.buttonPin = r;
}

void ButtonHandler::update() {
    
}