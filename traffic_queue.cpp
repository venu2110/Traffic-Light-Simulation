#include "traffic_queue.h"

void TrafficQueue::addCar(const std::string& carId) {
    cars.push(carId);
}

void TrafficQueue::removeCar() {
    if (!cars.empty()) cars.pop();
}

int TrafficQueue::getSize() const {
    return cars.size();
}

bool TrafficQueue::isEmpty() const {
    return cars.empty();
}

std::string TrafficQueue::frontCar() const {
    return cars.empty() ? "None" : cars.front();
}
