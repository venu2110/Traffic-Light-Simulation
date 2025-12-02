#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "traffic_queue.h"
#include "fsm.h"

void drawSignal(TrafficLightState state) {
    setfillstyle(SOLID_FILL, BLACK);
    bar(100, 100, 200, 300);

    setfillstyle(SOLID_FILL, state == STATE_RED ? RED : DARKGRAY);
    fillellipse(150, 130, 30, 30);

    setfillstyle(SOLID_FILL, state == STATE_YELLOW ? YELLOW : DARKGRAY);
    fillellipse(150, 190, 30, 30);

    setfillstyle(SOLID_FILL, state == STATE_GREEN ? GREEN : DARKGRAY);
    fillellipse(150, 250, 30, 30);
}

void showQueue(const TrafficQueue& tq) {
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(250, 100, const_cast<char*>("Car Queue:"));

    int y = 120;
    TrafficQueue copy = tq;

    while (!copy.isEmpty()) {
        std::string car = copy.frontCar();
        outtextxy(250, y, const_cast<char*>(car.c_str()));
        y += 20;
        copy.removeCar();
    }
}

int main() {
    initwindow(600, 400, "Traffic Light Simulation");

    TrafficQueue tq;
    TrafficFSM fsm;

    int count = 0;

    while (!kbhit()) {
        cleardevice();
        drawSignal(fsm.getState());

        tq.addCar("Car_" + std::to_string(count++));
        if (fsm.getState() == STATE_GREEN && !tq.isEmpty()) {
            tq.removeCar();
        }

        showQueue(tq);
        delay(fsm.getTimer() * 1000);
        fsm.nextState();
    }

    getch();
    closegraph();
    return 0;
}
