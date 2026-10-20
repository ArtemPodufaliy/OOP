
#include <iostream>
#include <string>
using namespace std;

// Class representing a car.
class Car {
public:
    string brand;
    double capacity, fuel, consumption;

    Car(string b, double c, double f, double cons) {
        brand = b;
        capacity = c;
        fuel = f;
        consumption = cons;
    }

    void refuel(double l) {
        fuel += l;
        if (fuel > capacity)
            fuel = capacity;
    }

    double drive(double km) {
        double possible = fuel * 100 / consumption;

        if (km < possible) {
            fuel -= km * consumption / 100;
            return km;
        } else {
            double distance = possible;
            fuel = 0;
            return distance;
        }
    }

    double range_left() {
        return fuel * 100 / consumption;
    }
};

int main() {
    Car c1("Toyota", 50, 10, 5);
    Car c2("Honda", 40, 20, 8);
    Car c3("Ford", 30, 0, 6);

    cout << c1.brand << ": " << c1.drive(100) << " km" << endl;
    cout << "Remaining range: " << c1.range_left() << " km" << endl;

    cout << c2.brand << ": " << c2.drive(1000) << " km" << endl;
    cout << c3.brand << ": " << c3.drive(50) << " km" << endl;

    c1.refuel(5);
    cout << "After refueling: " << c1.range_left() << " km" << endl;

    // Tests
    if (c1.range_left() != 100) return 1;
    if (c2.range_left() != 0) return 2;
    if (c3.range_left() != 0) return 3;

    cout << "All tests passed!" << endl;
    return 0;
}

