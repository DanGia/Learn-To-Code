#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 2000001
#define F(i, a, b) for (long long i = (long long)(a); i < (long long)(b); i++)

using namespace std;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res % p;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    ll powerten[n];
    ll inverseNine = modInverse(9, MOD);
    powerten[0] = 1;

    F(i, 1, n + 1)
    {
        powerten[i] = powerten[i - 1] * 10;
        powerten[i] %= MOD;
    }

    ll sum = 0;
    F(i, 1, n + 1)
    {
        int nos = s[i - 1] - '0';
        sum += (((((((powerten[n - i + 1] - 1) % MOD) * i) % MOD) * nos) % MOD) * inverseNine) % MOD;
        sum %= MOD;
    }
    cout << sum;
    return 0;
}