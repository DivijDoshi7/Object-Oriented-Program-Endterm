
car.exe : Vehicle.o Car.o main.o
	g++ Vehicle.o Car.o main.o -o car.exe


Vehicle.o : Vehicle.cpp
	g++ -c Vehicle.cpp

Car.o : Car.cpp
	g++ -c Car.cpp
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
