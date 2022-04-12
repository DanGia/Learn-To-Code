#include <bits/stdc++.h>
using namespace std;

string grh[8];
int n = 8;
int ans = 0;
bool c[8], d1[15], d2[15];

void backtrack(int r)
{
    if (r == 8)
    {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (grh[r][i] == '.' && !c[i] && !d1[r + i] && !d2[i - r + n - 1])
        {
            c[i] = d1[i + r] = d2[i - r + n - 1] = 1;
            backtrack(r + 1);
            c[i] = d1[i + r] = d2[i - r + n - 1] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < n; i++)
    {
        cin >> grh[i];
    }
    backtrack(0);
    cout << ans << endl;
    return 0;
}