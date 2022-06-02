#include <iostream>
using namespace std;

int *flatten(int **matrix, int r, int c)
{
    int *arr = new int[r * c];
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[cnt] = matrix[i][j];
            cnt++;
        }
    }
    return arr;
}

int main()

{
    int r = 0, c = 0;
    cin >> r >> c;
    int **matrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        matrix[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int *arr = flatten(matrix, r, c);
    for (int i = 0; i < r * c; i++)
    {
        cout << arr[i] << ' ';
    }
    if (arr == nullptr)
        cout << "NULL";
}