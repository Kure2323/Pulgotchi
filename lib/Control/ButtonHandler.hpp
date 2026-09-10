#pragma once

#include <Arduino.h>

enum class UMBRAL {
    LONG_PRESS = 100,
    GO_BACK = 5000
};

enum BUTTON_ACTION {
    LONG_PRESS,
    SHORT_PRESS,
    NONE
};

struct Button {
    const uint8_t* buttonPin;
    uint8_t deltaTime { 0 };
    BUTTON_ACTION rtAction { NONE };
    BUTTON_ACTION onLowAction { NONE };
    bool pressed { false };
};

class ButtonHandler {

    private:
    Button lButton;
    Button rButton;
    bool goBack = false;

    public:
    ButtonHandler(const uint8_t& leftButtonPin, const uint8_t& rightButtonPin);

    void update();


};