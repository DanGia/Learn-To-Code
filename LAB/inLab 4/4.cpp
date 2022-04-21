#include <iostream>
using namespace std;
template <typename T>
class Array
{
public:
    Array(int size, T initValue);
    ~Array();
    void print();

    Array(const Array<T> &other); // Copy Constructor

private:
    int size;
    T *p;
};
template <typename T>
Array<T>::Array(int size, T initValue)
{
    this->size = size;
    this->p = new T[size];
    for (int i = 0; i < size; i++)
    {
        this->p[i] = initValue;
    }
}
template <typename T>
Array<T>::Array(const Array<T> &other)
{
    this->size = other.size;
    T *tmp = new T[this->size];
    for (int i = 0; i < this->size; i++)
    {
        tmp[i] = other.p[i];
    }
    p = tmp;
}
template <typename T>
Array<T>::~Array()
{
}
template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}

// TODO
int main()
{
    Array<int> *a3;
    Array<int> *a4 = new Array<int>(10, 3);
    a3 = new Array<int>(*a4);
    delete a4;
    a3->print();
    delete a3;
}
