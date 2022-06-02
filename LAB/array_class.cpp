#include <iostream>
using namespace std;

template <typename T>
class Array
{
public:
    Array(int size, T initValue)
    {
        this->size = size;
        this->p = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->p[i] = initValue;
        }
    }
    ~Array()
    {
        delete p;
    }

    void setAt(int idx, const T &value);
    T getAt(int idx);

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
template <typename T>
void Array<T>::setAt(int idx, const T &value)
{
    if (idx < 0 || idx >= size)
        throw -1;
    this->p[idx] = value;
}

template <typename T>
T Array<T>::getAt(int idx)
{
    if (idx < 0 || idx >= size)
        throw -1;
    return this->p[idx];
}