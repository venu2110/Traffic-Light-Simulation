#ifndef TRAFFIC_QUEUE_H
#define TRAFFIC_QUEUE_H

#include <queue>
#include <string>

class TrafficQueue {
private:
    std::queue<std::string> cars;

public:
    void addCar(const std::string& carId);
    void removeCar();
    int getSize() const;
    bool isEmpty() const;
    std::string frontCar() const;
};

#endif
