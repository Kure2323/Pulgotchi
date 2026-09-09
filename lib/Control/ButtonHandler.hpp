#pragma once

#include <Arduino.h>

enum class UMBRAL {
    LONG_PRESS = 100,
    GO_BACK = 5000
};

enum BUTTON_EXPERIENCE {
    LONG_PRESS,
    SHORT_PRESS,
    NONE
};

struct Button {
    uint8_t buttonPin;
    uint8_t deltaTime = 0;
    BUTTON_EXPERIENCE exp = NONE;
};

class ButtonHandler {

    private:
    Button lButton;
    Button rButton;

    public:
    ButtonHandler(uint8_t leftButtonPin, uint8_t rightButtonPin);

    void update();


};