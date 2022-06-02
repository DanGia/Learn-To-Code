#include <iostream>
#include "function.cpp"
using namespace std;

template <typename T>
class Array2D
{
private:
    int r;
    int c;
    T **arr;

public:
    Array2D(int r, int c)
    {
        this->r = r;
        this->c = c;
        arr = new T *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new T[c];
        }
    }

    Array2D(int r, int c, T init)
    {
        this->r = r;
        this->c = c;
        arr = new T *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new T[c];
            for (int j = 0; j < c; j++)
            {
                this->arr[i][j] = init;
            }
        }
    }

    ~Array2D()
    {
        for (int i = 0; i < this->r; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    Array2D *operator*(const Array2D &other)
    {
        if (this->c != other.r)
        {
            return nullptr;
        }
        static Array2D array2d(this->r, other.c);

        T **tmp = new T *[array2d.r];

        for (int i = 0; i < array2d.r; i++)
        {
            for (int j = 0; j < array2d.c; j++)
            {
                tmp[i][j] = 0;
                for (int k = 0; k < this->c; k++)
                {
                    tmp[i][j] = this->arr[i][k] * other.arr[k][j];
                }
            }
        }
        array2d.arr = tmp;
        Array2D res = &array2d;
        return res;
    }

    int *operator[](const int index)
    {
        return arr[index];
    }

    int getR() { return this->r; }
    int getC() { return this->c; }

    void disp()
    {
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D<int> *p = new Array2D<int>(1, 2, 3);
    cout << (*p)[0][1] << endl;
    return 0;
}