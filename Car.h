#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    int getSpeed() const; 
    int getGear() const;  
};

#endif
