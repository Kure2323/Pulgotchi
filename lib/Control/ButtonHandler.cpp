#include <Arduino.h>
#include <ButtonHandler.hpp>


ButtonHandler::ButtonHandler(const uint8_t& l, const uint8_t& r) {
    lButton.buttonPin = &l;
    rButton.buttonPin = &r;
}


void ButtonHandler::update() {
    
    Button* buttons[2] {&lButton, &rButton};
    bool tempGoBack { false };
    goBack = false;

    for (Button* i : buttons) {

        int reading { digitalRead(*i->buttonPin) };
        uint32_t now { millis() };

        // Begins the countdown
        if (reading == HIGH && i->pressed == false) {
            i->pressed = true;
            i->deltaTime = now;
        } 

        // RT reading
        if (reading == HIGH && i->pressed == true) {
            uint32_t rtDiff = now - i->deltaTime;

            if (rtDiff >= int(UMBRAL::GO_BACK)) {
                if (tempGoBack) {
                    goBack = true;
                } else {
                    tempGoBack = true;
                }
            }

            if (rtDiff < int(UMBRAL::LONG_PRESS)) {
                i->rtAction = BUTTON_ACTION::SHORT_PRESS;
            } else if (rtDiff >= int(UMBRAL::LONG_PRESS)) {
                i->rtAction = BUTTON_ACTION::LONG_PRESS;
            }

        }

        // Once it is no longer pressed
        if (reading == LOW && i->pressed == true) {
            goBack = false;
            i->pressed = false;
            i->rtAction = BUTTON_ACTION::NONE;
            uint32_t diff = now - i->deltaTime;

            if (diff < int(UMBRAL::LONG_PRESS)) {
                i->onLowAction = BUTTON_ACTION::SHORT_PRESS;
            } else if (diff >= int(UMBRAL::LONG_PRESS)) {
                i->onLowAction = BUTTON_ACTION::LONG_PRESS;
            }
        }
        
        


    }

}