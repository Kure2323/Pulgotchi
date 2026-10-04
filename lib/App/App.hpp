#pragma once

#include <Arduino.h>
#include <ButtonHandler.hpp>


class App { // Intended to be an interface
private:
    const std::string title;
    ButtonHandler* button_handler = nullptr;
    bool isGoBackBlocked { false };


public:
    App();
    void giveControl(ButtonHandler* button_handler);
    ~App();
    void load();
    void shut();
    void update();
};


