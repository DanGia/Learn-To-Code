#include <bits/stdc++.h>
using namespace std;

int fastMult(int a, int b, int m)
{
    if (b == 0)
    {
        return 0;
    }
    int res = fastMult(a, b / 2, m);
    res = (res + res) % m;
    if (b % 2 == 1)
    {
        res = (res + a) % m;
    }
    return res;
}

// litle Fermat
int fastPow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int res = fastPow(a, b / 2, m);
    res = (res * res) % m;
    if (b % 2 == 1)
    {
        res = (res * a) % m;
    }
    return res;
}

int main()
{
}