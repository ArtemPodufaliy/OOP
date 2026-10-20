#include <iostream>
#include <cassert>
using namespace std;

// Class representing a light switch.
class LightSwitch {
public:
    bool on;
    int count;

    LightSwitch() {
        on = false;
        count = 0;
    }

    void toggle() {
        on = !on;
        count++;
    }

    bool is_on() {
        return on;
    }

    int switches() {
        return count;
    }
};

int main() {
    LightSwitch s1, s2, s3;

    s1.toggle();
    s1.toggle();
    s2.toggle();

    cout << "Switch 1 is on: " << s1.is_on() << endl;
    cout << "Switch 1 toggles: " << s1.switches() << endl;

    assert(!s1.is_on());
    assert(s1.switches() == 2);
    assert(s2.is_on());
    assert(s3.switches() == 0);

    cout << "All tests passed!" << endl;

    return 0;
}
