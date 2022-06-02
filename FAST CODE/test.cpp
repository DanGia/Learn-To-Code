#include <iostream>
using namespace std;

int main(void)
{
    int ro = 3, co = 2;
    int **array = new int *[ro];

    for (int i = 0; i < ro; i++)
    {
        array[i] = new int[co];
    }
    // fill and print the matrix
    for (int i = 0; i < ro; i++)
    {
        for (int j = 0; j < co; j++)
        {
            array[i][j] = i;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int rowToDel = 1;
    delete[] array[rowToDel];
    int **tmp = new int *[ro - 1];
    int id = 0;
    for (int i = 0; i < ro; ++i)
        if (i != rowToDel)
            tmp[id++] = array[i];
    delete[] array;
    array = tmp;
    ro = ro - 1;

    cout << "Array after deleting " << rowToDel << "-th row\n";
    for (int i = 0; i < ro; i++)
    {
        for (int j = 0; j < co; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}