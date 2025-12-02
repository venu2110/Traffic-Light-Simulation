#ifndef FSM_H
#define FSM_H

enum TrafficLightState {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
};

class TrafficFSM {
private:
    TrafficLightState currentState;
    int timer;

public:
    TrafficFSM();
    void nextState();
    TrafficLightState getState() const;
    int getTimer() const;
};

#endif
