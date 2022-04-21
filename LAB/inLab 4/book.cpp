// string.h is included
#include <iostream>
#include <string.h>
using namespace std;
class Book
{
    char *name;

public:
    Book(const char *);
    ~Book();

    void display();
    char *getName();
};

void Book::display()
{
    cout << "Book: " << this->name << endl;
}

char *Book::getName()
{
    return this->name;
}

// TODO: Book and ~Book
Book::Book(const char *ch)
{
    int size = strlen(ch);
}
Book::~Book()
{
}

int main()
{
    Book *pBook = new Book("To Kill a Mockingbird");
    pBook->display();
    delete pBook;
}