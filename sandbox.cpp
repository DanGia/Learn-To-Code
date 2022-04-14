#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
const long long MAX = 1000005;

ll fact[MAX];

ll expo(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % MOD;
        }
        b /= 2;
        a = (a * a) % MOD;
    }
    return res;
}

ll inverse(ll b)
{
    ll x = expo(b, MOD - 2);

    if ((x * b) % MOD == 1)
    {
        return x;
    }

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b, d;

    fact[0] = 1;
    for (int i = 0; i < MAX; i++)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    while (cin >> n >> a >> b >> d)
    {
    }

    return 0;
}