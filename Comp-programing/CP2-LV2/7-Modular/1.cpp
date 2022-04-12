#include <bits/stdc++.h>
using namespace std;

int mod(string &n, int m)
{
    int res = 0;
    for (int i = 0; i < n.size(); i++)
    {
        res = (res * 10 + (n[i] - '0')) % m;
    }
    return res;
}

int main()
{
    string n;
    cin >> n;
    vector<bool> div(10, false);
    for (int i = 1; i <= 9; i++)
    {
        if (mod(n, i) == 0)
            div[i] = true;
    }

    int res = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (div[n[i] - '0'] == true)
            res++;
    }
    cout << res << "\n";
    return 0;
}
