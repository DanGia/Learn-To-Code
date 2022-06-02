#include <bits/stdc++.h>
using namespace std;

int non_fibo(int n)
{
    int f1 = 1, f2 = 2, cur = 3;

    while (n > 0)
    {
        f1 = f2;
        f2 = cur;
        cur = f2 + f1; // continue
        n -= (cur - f2 - 1);
    }
    int res = n + (cur - 1);
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << non_fibo(n);
    return 0;
    
}