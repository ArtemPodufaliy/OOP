#include <iostream>
#include <cassert>
using namespace std;

// Class representing a counter.
class Counter {
public:
    int count;

    Counter() {
        count = 0;
    }

    void increment() {
        count++;
    }

    void decrement() {
        if (count > 0)
            count--;
    }

    void reset() {
        count = 0;
    }

    int value() {
        return count;
    }
};

int main() {
    Counter c1, c2, c3;

    c1.increment();
    c1.increment();
    c2.decrement();

    cout << "Counter 1: " << c1.value() << endl;
    cout << "Counter 2: " << c2.value() << endl;

    assert(c1.value() == 2);
    assert(c2.value() == 0);
    assert(c3.value() == 0);

    c1.reset();
    assert(c1.value() == 0);

    cout << "All tests passed!" << endl;

    return 0;
}
