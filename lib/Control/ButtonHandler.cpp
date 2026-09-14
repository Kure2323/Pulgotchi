#include <Arduino.h>
#include <ButtonHandler.hpp>


ButtonHandler::ButtonHandler(const uint8_t& leftButtonPin, const uint8_t& rightButtonPin) {
    lButton.buttonPin = &leftButtonPin;
    rButton.buttonPin = &rightButtonPin;
}

Button ButtonHandler::getButton(const uint8_t buttonPin) const {
    if (buttonPin == *lButton.buttonPin) {
        return lButton;
    }
    if (buttonPin == *rButton.buttonPin) {
        return rButton;
    }

    Serial.println("Returning default button (left)");
    return lButton;
}

static BUTTON_ACTION manageAction(const uint32_t& diff) {
    if (diff < static_cast<int>(UMBRAL::LONG_PRESS)) {
        return BUTTON_ACTION::SHORT_PRESS;
    }
    return BUTTON_ACTION::LONG_PRESS;
}

void ButtonHandler::update() {
    
    Button* buttons[2] {&lButton, &rButton};
    bool tempGoBack { false };
    goBack = false;

    for (Button* i : buttons) {

        const int reading { digitalRead(*i->buttonPin) };
        const uint32_t now { millis() };

        // Begins the countdown
        if (reading == HIGH && i->pressed == false) {
            i->pressed = true;
            i->deltaTime = now;
        } 

        // RT reading
        if (reading == HIGH && i->pressed == true) {
            const uint32_t rtDiff = now - i->deltaTime;

            if (rtDiff >= static_cast<int>(UMBRAL::GO_BACK)) {
                if (tempGoBack) {
                    goBack = true;
                } else {
                    tempGoBack = true;
                }
            }

            i->rtAction = manageAction(rtDiff);

        }

        // Once it is no longer pressed
        if (reading == LOW && i->pressed == true) {
            goBack = false;
            i->pressed = false;
            i->rtAction = BUTTON_ACTION::NONE;
            const uint32_t diff = now - i->deltaTime;

            i->onLowAction = manageAction(diff);
        }
        
        


    }

}
