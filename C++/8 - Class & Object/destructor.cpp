#include <iostream>
using namespace std;

class HelloWorld
{
public:
    HelloWorld()
    {
        cout << "Constructor is called" << endl;
    }
    // Destructor
    ~HelloWorld()
    {
        cout << "Destructor is called" << endl;
    }

    // Member function

    void display()
    {
        cout << "Hello World" << endl;
    }
};

int main()
{
    HelloWorld obj;
    obj.display();
    return 0;
}