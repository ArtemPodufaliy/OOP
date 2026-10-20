#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Class representing a stack of integers.
class Stack {
public:
    vector<int> data;

    Stack() {}

    void push(int x) {
        data.push_back(x);
    }

    // Returns -1 if the stack is empty.
    int pop() {
        if (data.empty())
            return -1;

        int x = data.back();
        data.pop_back();
        return x;
    }

    // Returns -1 if the stack is empty.
    int peek() {
        if (data.empty())
            return -1;

        return data.back();
    }

    int size() {
        return data.size();
    }

    bool is_empty() {
        return data.empty();
    }
};

int main() {
    Stack s1, s2, s3;

    s1.push(10);
    s1.push(20);
    s2.push(5);

    cout << "Top: " << s1.peek() << endl;
    cout << "Removed: " << s1.pop() << endl;
    cout << "Size: " << s1.size() << endl;

    assert(s1.peek() == 10);
    assert(s1.size() == 1);
    assert(s2.pop() == 5);
    assert(s3.is_empty());
    assert(s3.pop() == -1);

    cout << "All tests passed!" << endl;

    return 0;
}
