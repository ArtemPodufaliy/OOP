#include <iostream>
#include <cassert>
using namespace std;

// Class representing a rectangle.
class Rectangle {
public:
    int width, height;

    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }

    bool is_square() {
        return width == height;
    }
};

int main() {
    Rectangle r1(4, 5);
    Rectangle r2(3, 3);
    Rectangle r3(2, 6);

    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;
    cout << "Is square: " << r2.is_square() << endl;

    assert(r1.area() == 20);
    assert(r1.perimeter() == 18);
    assert(r2.is_square());
    assert(!r3.is_square());

    cout << "All tests passed!" << endl;

    return 0;
}
