#include <iostream>
using namespace std;

// TODO
class Integer
{
private:
    int val;

public:
    Integer(int val)
    {
        this->val = val;
    }
    Integer(Integer *p)
    {
        this->val = p->val;
    }
    Integer operator+(Integer *p)
    {
        return Integer(this->val + p->val);
    }
    Integer operator+(int value)
    {
        return Integer(value + this->val);
    }
    void print();
};

void Integer::print()
{
    cout << this->val << endl;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer *t = new Integer(z);
    Integer c(t);

    a.print();
    b.print();
    (a + b + c + 4).print();

    delete t;
    return 0;
}