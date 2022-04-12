#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int n;
int a[MAXN];
int bin[MAXN];
int res = 0;
int chk = 0;
int cnt = 0;
// generating binary
//  if 1 clockwise
// if 0 counter
void check()
{
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bin[i] == 1)
        {
            tmp += a[i];
        }
        else if (bin[i] == 0)
        {
            tmp -= a[i];
        }
    }
    res = tmp;
    if (res % 360 == 0)
        chk = 1;
    else
        chk = 0;
}
void genBinary(int i)
{
    if (i == n + 1)
    {
        check();
        if (chk == 1)
            cnt++;
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
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    genBinary(1);
    if (cnt > 0)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
