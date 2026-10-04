
#include "HomeMenu.hpp"


HomeMenu::HomeMenu()
    : games{ // Add here all games
        App(),
        App()
    }, apps{ // Add here all apps
        App(),
        App()
    } {}

void HomeMenu::giveControl(ButtonHandler *button_handler) {
    this->button_handler = button_handler;
}

HomeMenu::HomeMenu(std::vector<App> _games, std::vector<App> _apps):
    games(_games), apps(_apps) { };

HomeMenu::~HomeMenu() = default;

void HomeMenu::openApp(App * app) {
    if (app == nullptr) {
        Serial.println("ERROR: could not find app to load.");
        return;
    }
    showMenu = false;
    runningApp = app;
    runningApp->load();
}

void HomeMenu::closeApp() {
    if (runningApp == nullptr) {
        Serial.println("ERROR: could not find running app to close.");
    }
    runningApp->shut();
    showMenu = true;
    runningApp = nullptr;
}

void HomeMenu::update() {

    if (runningApp != nullptr) {
        return;
    }

    const Button rButton = button_handler->getButton('r');
    const Button lButton = button_handler->getButton('l');


    if (rButton.onLowAction == BUTTON_ACTION::SHORT_PRESS) {
        selectedApp++;
        const uint8_t numApps = apps.size();

        if (selectedApp >= numApps) {
            selectedApp -= numApps;
        }

    }

    if (lButton.onLowAction == BUTTON_ACTION::SHORT_PRESS) {
        selectedGame++;
        const uint8_t numGames = games.size();

        if (selectedApp >= numGames) {
            selectedApp -= numGames;
        }

    }

}
