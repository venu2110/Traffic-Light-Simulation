#include "fsm.h"

TrafficFSM::TrafficFSM() {
    currentState = STATE_RED;
    timer = 4;
}

void TrafficFSM::nextState() {
    switch (currentState) {
        case STATE_RED:
            currentState = STATE_GREEN;
            timer = 4;
            break;
        case STATE_GREEN:
            currentState = STATE_YELLOW;
            timer = 3;
            break;
        case STATE_YELLOW:
            currentState = STATE_RED;
            timer = 2;
            break;
    }
}

TrafficLightState TrafficFSM::getState() const {
    return currentState;
}

int TrafficFSM::getTimer() const {
    return timer;
}
