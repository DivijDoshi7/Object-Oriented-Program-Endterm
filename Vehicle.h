#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
protected:
    int speed;
    int gear;

public:
    Vehicle();
    void accelerate(int increment);
    void brake(int decrement);
    void shiftGear(int newGear);
    void displayInfo();
};

#endif
