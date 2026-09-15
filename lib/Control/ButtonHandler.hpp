#pragma once

#include <Arduino.h>

enum class UMBRAL {
    LONG_PRESS = 100,
    GO_BACK = 5000
};

enum class BUTTON_ACTION {
    LONG_PRESS,
    SHORT_PRESS,
    NONE
};

struct Button {
    const uint8_t* buttonPin { };
    uint8_t deltaTime { 0 };
    BUTTON_ACTION rtAction { BUTTON_ACTION::NONE };
    BUTTON_ACTION onLowAction { BUTTON_ACTION::NONE };
    bool pressed { false };
};

class ButtonHandler {

private:
    Button lButton;
    Button rButton;
    bool goBack = false;

public:
    ButtonHandler(const uint8_t& leftButtonPin, const uint8_t& rightButtonPin);
    Button getButton(uint8_t buttonPin) const;

    void update();


};