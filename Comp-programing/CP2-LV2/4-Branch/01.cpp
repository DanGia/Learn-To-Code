#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

int n, L, R, X, c[MAXN];
int bin[MAXN];
int res = 0;

void check()
{
    int sum = 0;
    int Min = 1e9, Max = 0;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (bin[i] == 1)
        {
            sum += c[i];

            Min = min(Min, c[i]);
            Max = max(Max, c[i]);

            cnt++;
        }
    }
    if (cnt >= 2 && sum >= L && sum <= R && Max - Min >= X)
        res++;
}

void genBinary(int i)
{
    if (i == n + 1)
    {
        check();
        return;
    }
    for (int j = 0; j <= 1; j++)
    {
        bin[i] = j;
        genBinary(i + 1);
    }
}
int main()
{
    cin >> n >> L >> R >> X;
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    genBinary(1);
    cout << res;
    return 0;
}
