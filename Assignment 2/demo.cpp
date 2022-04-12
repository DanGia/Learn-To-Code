#include <bits/stdc++.h>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0);
    string toString()
    {
        string str;

        str = "<Point[" + to_string(x) + "," + to_string(y);
        return str;
    }

    string toString() const;

    int distanceTo(const Point &otherPoint) const;
};
int main()
{
    Point p1(0, 5);
    cout << p1.toString() << endl;
    Point p2(9, 3);
    cout << p2.toString() << endl;
}