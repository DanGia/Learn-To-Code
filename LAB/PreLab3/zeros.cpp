#include <bits/stdc++.h>
using namespace std;

int *zeros(int n)
{
    int *a = new int[n];
    if (n <= 0)
    {
        return nullptr;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    cout << zeros(n);
}