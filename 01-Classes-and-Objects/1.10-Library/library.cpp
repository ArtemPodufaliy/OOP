
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// Class representing a book.
class Book {
public:
    string title, author;
    int pages;

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
};

// Class representing a library.
class Library {
public:
    vector<Book> books;

    Library() {}

    void add(Book book) {
        books.push_back(book);
    }

    vector<Book> find(string author) {
        vector<Book> result;

        for (Book b : books) {
            if (b.author == author)
                result.push_back(b);
        }

        return result;
    }

    int total_pages() {
        int total = 0;

        for (Book b : books)
            total += b.pages;

        return total;
    }

    string longest() {
        if (books.empty())
            return "";

        Book best = books[0];

        for (Book b : books) {
            if (b.pages > best.pages)
                best = b;
        }

        return best.title;
    }
};

int main() {
    Library lib1, lib2;

    Book b1("1984", "Orwell", 300);
    Book b2("Animal Farm", "Orwell", 100);
    Book b3("The Hobbit", "Tolkien", 400);

    lib1.add(b1);
    lib1.add(b2);
    lib1.add(b3);

    lib2.add(Book("Short Book", "Author", 50));

    cout << "Total pages: " << lib1.total_pages() << endl;
    cout << "Books by Orwell: " << lib1.find("Orwell").size() << endl;
    cout << "Longest book: " << lib1.longest() << endl;

    assert(lib1.total_pages() == 800);
    assert(lib1.find("Orwell").size() == 2);
    assert(lib1.longest() == "The Hobbit");
    assert(lib2.total_pages() == 50);
    assert(lib1.find("Unknown").empty());

    cout << "All tests passed!" << endl;

    return 0;
}

