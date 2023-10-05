#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <cassert>

int main() {
    try {
        Car* myCar = new Car();
        int lastGear = 1; // To keep track of the last gear for automatic speed increase

        while (true) {
            std::cout << "Choose an option:" << std::endl;
            std::cout << "1. Accelerate" << std::endl;
            std::cout << "2. Brake" << std::endl;
            std::cout << "3. Shift Gear" << std::endl;
            std::cout << "4. Quit" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 4) {
                break;
            }

            switch (choice) {
                case 1: {
                    int acceleration;
                    while (true) {
                        std::cout << "Enter acceleration value (mph): ";
                        if (std::cin >> acceleration && acceleration > 0) {
                            myCar->accelerate(acceleration);
                            break;
                        } else {
                            std::cout << "Invalid input. Please enter a positive integer for acceleration." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                }
                case 2: {
                    // Apply braking (speed decreases by 10 mph, but not below 0)
                    myCar->brake(10);
                    if (myCar->getSpeed() < 0) {
                        myCar->accelerate(-myCar->getSpeed()); // Set speed to 0 if it goes negative
                    }
                    break;
                }
                case 3: {
                    int gear;
                    while (true) {
                        std::cout << "Enter gear (1-5): ";
                        if (std::cin >> gear && gear >= 1 && gear <= 5) {
                            // Calculate the speed increase due to gear change
                            int gearChangeSpeed = (gear - lastGear) * 5;
                            if (gearChangeSpeed > 0) {
                                myCar->accelerate(gearChangeSpeed);
                            }
                            myCar->shiftGear(gear);
                            lastGear = gear;
                            break;
                        } else {
                            std::cout << "Invalid input. Please enter a number between 1 and 5 for gear." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                    break;
                }
                default:
                    std::cout << "Invalid choice. Try again." << std::endl;
            }

            myCar->displayInfo();

            // Check if speed is zero and shift to gear 1
            if (myCar->getSpeed() == 0 && myCar->getGear() != 1) {
                int gearChangeSpeed = (1 - myCar->getGear()) * 5;
                if (gearChangeSpeed > 0) {
                    myCar->accelerate(gearChangeSpeed);
                }
                myCar->shiftGear(1);
                lastGear = 1;
                std::cout << "The car is now stopped and shifted to gear 1." << std::endl;
            }
        }

        // Deleting the dynamically allocated object
        delete myCar;

    } catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
    }

    return 0;
}
