#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Class representing a student.
class Student {
public:
    string surname;
    vector<int> grades;

    Student(string s) {
        surname = s;
    }

    void add_grade(int g) {
        grades.push_back(g);
    }

    double average() {
        if (grades.empty())
            return 0;

        int sum = 0;
        for (int g : grades)
            sum += g;

        return (double)sum / grades.size();
    }

    int best() {
        if (grades.empty())
            return 0;

        int max_grade = grades[0];
        for (int g : grades)
            if (g > max_grade)
                max_grade = g;

        return max_grade;
    }

    bool has_debt() {
        for (int g : grades)
            if (g < 60)
                return true;

        return false;
    }
};

int main() {
    Student s1("Smith");
    Student s2("Brown");
    Student s3("Taylor");

    s1.add_grade(80);
    s1.add_grade(100);
    s2.add_grade(50);
    s3.add_grade(90);

    cout << s1.surname << " average: " << s1.average() << endl;
    cout << s2.surname << " has debt: " << s2.has_debt() << endl;

    assert(s1.average() == 90);
    assert(s1.best() == 100);
    assert(s2.has_debt());
    assert(!s3.has_debt());

    cout << "All tests passed!" << endl;

    return 0;
}
