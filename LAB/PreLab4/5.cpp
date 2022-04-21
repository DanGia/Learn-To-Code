#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T &value);
    T getAt(int idx);
    T &operator[](int idx);

    void print();

private:
    int size;
    T *p;
};

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        cout << (i > 0 ? " " : "")
             << this->p[i];
    }
    cout << endl;
}

// TODO
int main()
{
    Array<int> a9(1000, 7);
    a9.setAt(0, 99);
    cout << "Subscript Array["
         << 0 << "]:"
         << a9[0] << endl;
    a9[0] = -99;
    a9.print();
}