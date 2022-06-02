#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2)
        return n;
    int f1 = 0, f2 = 1;
    int res = 0;
    for (int i = 2; i <= n; i++)
    {
        res = f2 + f1;
        f1 = f2;
        f2 = res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n + 1) * fibo(n - 1) - fibo(n) * fibo(n);
    return 0;
}