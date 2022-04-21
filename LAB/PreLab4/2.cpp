#include <iostream>
using namespace std;

class Room
{
private:
    double length;
    double breadth;
    double height;

public:
    Room(double l, double b, double h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    double calculateArea()
    {
        return length * breadth;
    }
    double calculateVolume()
    {
        return length * height * breadth;
    }
};

int main()
{

    cout << "Constructor test";
    Room r(20, 3, 4);
    Room *r2 = new Room(10.5, 5.5, 5.4);
    delete r2;
}