#include <iostream>
#include <cassert>
#include <string>
using namespace std;

// Class representing a product.
class Product {
public:
    string name;
    double price;
    double discount;

    Product(string n, double p) {
        name = n;
        price = p;
        discount = 0;
    }

    double final_price() {
        return price * (1 - discount / 100);
    }

    void set_discount(double p) {
        if (p >= 0 && p <= 100)
            discount = p;
    }

    double total(int qty) {
        return final_price() * qty;
    }
};

int main() {
    Product p1("Phone", 1000);
    Product p2("Mouse", 50);
    Product p3("Book", 20);

    p1.set_discount(10);
    p2.set_discount(0);
    p3.set_discount(100);

    cout << p1.name << ": " << p1.final_price() << endl;
    cout << "Total for 2 phones: " << p1.total(2) << endl;

    assert(p1.final_price() == 900);
    assert(p2.final_price() == 50);
    assert(p3.final_price() == 0);
    assert(p1.total(2) == 1800);
    assert(p2.total(0) == 0);

    cout << "All tests passed!" << endl;

    return 0;
}
