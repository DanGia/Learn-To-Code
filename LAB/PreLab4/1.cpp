#include <iostream>
using namespace std;

class Integer
{
private:
    int val;

public:
    Integer(int x)
    {
        val = x;
    }
    void setValue(int v)
    {
        val = v;
    }
    int getValue()
    {
        return val;
    }
};

int main()
{
    Integer i(10);
    cout << i.getValue();
}