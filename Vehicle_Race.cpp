#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    const int numCars = 4;
    std::vector<Car> cars(numCars);

    int raceDistance = 1000; // Distance to race (in miles)
    bool raceOver = false;
    
    while (!raceOver) {
        system("clear"); // Clear the console (for Linux/macOS, use "cls" for Windows)
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Delay for visualization
        
        // Simulate each car's actions (accelerate, brake, shift gear)
        for (int i = 0; i < numCars; ++i) {
            int choice = std::rand() % 3 + 1; // Random choice: 1 = Accelerate, 2 = Brake, 3 = Shift Gear
            int value = std::rand() % 20 + 1; // Random value (e.g., acceleration, braking)
            
            switch (choice) {
                case 1:
                    cars[i].accelerate(value);
                    break;
                case 2:
                    cars[i].brake(10); // Brake with a fixed value of 10 mph
                    break;
                case 3:
                    cars[i].shiftGear(std::rand() % 5 + 1); // Random gear shift (1-5)
                    break;
            }
            
            // Check if a car has crossed the race distance
            if (cars[i].getSpeed() > 0) {
                cars[i].accelerate(-cars[i].getSpeed()); // Slow down to stop after crossing the finish line
                if (raceDistance <= 0) {
                    raceOver = true;
                }
            }
        }
        
        // Display car information
        for (int i = 0; i < numCars; ++i) {
            std::cout << "Car " << i + 1 << ": ";
            cars[i].displayInfo();
        }
        
        raceDistance -= 10; // Decrease the race distance
        
        if (raceOver) {
            std::cout << "Race over! All cars have crossed the finish line." << std::endl;
        }
    }
    
    return 0;
}
