
#include <iostream>
#include <cassert>
using namespace std;

// Class representing a book.
class Book {
public:
    string title, author;
    int pages, current_page;

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
        current_page = 0;
    }

    void read(int n) {
        current_page += n;
        if (current_page > pages)
            current_page = pages;
    }

    double progress() {
        return 100.0 * current_page / pages;
    }

    bool is_finished() {
        return current_page == pages;
    }
};

int main() {
    Book b1("1984", "George Orwell", 100);
    Book b2("The Hobbit", "Tolkien", 50);
    Book b3("Animal Farm", "George Orwell", 80);

    b1.read(30);
    b2.read(60);

    cout << b1.title << ": " << b1.progress() << "%" << endl;
    cout << b2.title << ": " << b2.progress() << "%" << endl;

    assert(b1.progress() == 30);
    assert(b2.is_finished());
    assert(!b3.is_finished());

    b1.read(100);
    assert(b1.is_finished());

    cout << "All tests passed!" << endl;

    return 0;
}
