#include <Pet.hpp>
#include <Arduino.h>

constexpr uint8_t MAX_VALUE = 255;
constexpr uint8_t ADD_VALUE = 51;
constexpr uint8_t LIMIT_VALUE = 153;

uint8_t Pet::getSadness() {
    return sadness;
}

uint8_t Pet::getHungry() {
    return hungry;
}

uint8_t Pet::getAnger() {
    return anger;
}

uint8_t Pet::getTiredness() {
    return tiredness;
}

uint8_t Pet::getBoredness() {
    return boredness;
}

void Pet::increaseSadness() {
    if (sadness != MAX_VALUE) {
        Serial.println("Incrissing sadness...");
        sadness += ADD_VALUE;
    }
}

void Pet::increaseHungry() {
    if (hungry != MAX_VALUE) {
        Serial.println("Incrissing hungry...");
        hungry += ADD_VALUE;
    }
}

void Pet::increaseAnger() {
    if (anger != MAX_VALUE) {
        Serial.println("Incrissing anger...");
        anger += ADD_VALUE;
    }
}

void Pet::increaseTiredness() {
    if (tiredness != MAX_VALUE) {
        Serial.println("Incrissing tiredness...");
        tiredness += ADD_VALUE;
    }
}

void Pet::update() {
    {
        unsigned long now = millis();
        if (now - lastCheck < UPDATE_TIME) {
            return;
        }
        lastCheck = now;
    }
    
    // Chaos
    if (random(10000) == 0) {
        sadness = MAX_VALUE;
        hungry = MAX_VALUE;
        anger = MAX_VALUE;
        tiredness = MAX_VALUE;
        return;
    }

    if (random(10) == 0) {
                
        switch (random(3)) {
            case 0:
                increaseSadness();
                break;
            case 1:
                increaseHungry();
                if (hungry == MAX_VALUE) {
                    increaseAnger();
                }
                break;
            case 2:
                increaseTiredness();
                break;
        }

    }

    manageMood();

    Serial.print("Sadness=");
    Serial.println(sadness);

    Serial.print("Hungry=");
    Serial.println(hungry);

    Serial.print("Anger=");
    Serial.println(anger);

    Serial.print("Tiredness=");
    Serial.println(tiredness);

    Serial.print("Boredness=");
    Serial.println(boredness);

    Serial.printf("Mood=%d\n", actualMood);

    Serial.println('\n');
}

void Pet::manageMood() {

    /**
     * sadness -> Level of sadness. The less it has, the happier it gets
     * hungry -> The higher it gets the hungrier it gets 
     * anger -> Level of anger. Meaningless rn
     * tiredness -> The lower it gets the more energy it has
     */

    /*
        Phases:                        MAX
            0 - 51 - 102 - 153 - 204 - 255
    */
    

    // Sadness
    if (sadness < MAX_VALUE &&
        sadness > 0) {
        actualMood = MOOD::NORMAL;
    } else if (sadness == 0) {
        actualMood = MOOD::HAPPY;
    } else if (sadness == MAX_VALUE) {
        actualMood = MOOD::SAD;
    }

    if (sadness < LIMIT_VALUE && random(5) == 0) {
        actualMood == MOOD::HAPPY;
    }


    // Tiredness
    if (tiredness == MAX_VALUE) {
        actualMood = MOOD::TIRED;
    }


    // Hungry
    if (hungry == MAX_VALUE) {
        actualMood = MOOD::HUNGRY;
    } else if (hungry > LIMIT_VALUE){
        if (random(3) == 0) {
            actualMood = MOOD::HUNGRY;
        }
    } 


    // Anger
    if (anger == MAX_VALUE) {
        actualMood = MOOD::ANGRY;
    }

    // Retarded
    if (sadness == MAX_VALUE &&
        hungry == MAX_VALUE &&
        anger == MAX_VALUE &&
        tiredness == MAX_VALUE &&
        boredness == MAX_VALUE) {

        actualMood = MOOD::RETARDED;
    }

}