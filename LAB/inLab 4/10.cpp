#include <iostream>
using namespace std;
template <typename T>
class Array
{
public:
    Array(int size, T initValue);
    ~Array();
    void print();

    Array(const Array<T> &other); // Copy Conustructor
    Array<T> &operator=(const Array<T> &other)
    {
        cout << "Call assignment operator" << endl;
        this->size = other.size;
        T *tmp = new T[this->size];
        for (int i = 0; i < this->size; i++)
        {
            tmp[i] = other.p[i];
        }
        p = tmp;
        // return ;
    } // Copy assignment operator

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
    cout << "Call copy constructor" << endl;
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
    // // Test copy assignment operator
    Array<int> *a5 = new Array<int>(1, 2);
    Array<int> *a6 = new Array<int>(12, 5);
    *a5 = *a6;
    delete a6;
    a5->print();
    delete a5;
}
