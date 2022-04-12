#include <bits/stdc++.h>
using namespace std;

int n, L, R, x;
const int MAXN = 25;
int c[MAXN];

bool check(vector<int> &b)
{
    int sum = 0;
    int Max = 0, Min = 1e9;
    int cnt = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 1)
        {
            sum += c[i];
            Max = max(Max, c[i]);
            Min = min(Min, c[i]);
            cnt++;
        }
    }
    return (cnt >= 2 && sum >= L && sum <= R && Max - Min >= x);
}

bool nextBinary(vector<int> &b)
{
    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            for (int j = i + 1; j < b.size(); j++)
                b[j] = 0;
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> L >> R >> x;
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> binary(n, 0);
    int res = 0;
    while (nextBinary(binary))
    {
        if (check(binary))
            res++;
    }

    cout << res;
    return 0;
}