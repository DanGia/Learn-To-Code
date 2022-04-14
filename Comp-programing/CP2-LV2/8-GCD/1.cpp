#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0)
    {
        if (a >= b)
        {
            a %= b;
        }
        else
            b %= a;
    }
    return a + b;
}

int calG(int N)
{
    int g = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            g += gcd(i, j);
        }
    }
    return g;
}

int main()
{

    while (true)
    {

        int n;
        cin >> n;
        if (n == 0)
            break;
        else
            cout << calG(n) << endl;
    }
    // cout << calG(n);
    return 0;
}