#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    int getSpeed() const; // Getter for speed
    int getGear() const;  // Getter for gear
};

#endif
