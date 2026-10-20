#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

// Class representing a point on a plane.
class Point {
private:
    double x, y;

public:
    // Constructor
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    // Calculates distance to another point.
    double distance_to(Point other) {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    // Moves the point.
    void move(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Checks whether the point is the origin.
    bool is_origin() {
        return x == 0 && y == 0;
    }

    double get_x() { return x; }
    double get_y() { return y; }
};

int main() {
    // Demonstration
    Point p1(0, 0);
    Point p2(3, 4);
    Point p3(1, 2);

    p3.move(2, 3);

    cout << "Distance: " << p1.distance_to(p2) << endl;
    cout << "P1 is origin: " << p1.is_origin() << endl;
    cout << "P3: (" << p3.get_x() << ", " << p3.get_y() << ")" << endl;

    // Tests
    assert(p1.is_origin());                       // Test 1
    assert(p1.distance_to(p2) == 5);              // Test 2
    assert(p3.get_x() == 3 && p3.get_y() == 5);  // Test 3

    p2.move(-3, -4);
    assert(p2.is_origin());                       // Test 4

    cout << "All tests passed!" << endl;

    return 0;
}
