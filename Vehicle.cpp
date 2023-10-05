#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() : speed(0), gear(1) {}

void Vehicle::accelerate(int increment) {
    if (increment > 0) {
        speed += increment;
        std::cout << "Accelerating by " << increment << " mph." << std::endl;
    } else {
        throw "Invalid acceleration value. Must be greater than 0.";
    }
}

void Vehicle::brake(int decrement) {
    if (decrement > 0) {
        speed -= decrement;
        std::cout << "Applying brakes by " << decrement << " mph." << std::endl;
    } else {
        throw "Invalid braking value. Must be greater than 0.";
    }
}

void Vehicle::shiftGear(int newGear) {
    if (newGear >= 1 && newGear <= 5) {
        gear = newGear;
        std::cout << "Shifting to gear " << newGear << std::endl;
    } else {
        throw "Invalid gear value. Must be between 1 and 5.";
    }
}

void Vehicle::displayInfo() {
    std::cout << "Current Speed: " << speed << " mph, Current Gear: " << gear << std::endl;
}
