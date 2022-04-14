#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

#define max 1000005
ll fact[max];
// tinh giai thua
ll expo(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % mod;

        b /= 2;
        a = (a * a) % mod;
    }
    return res;
}

ll mod_inverse(ll b)
{
    ll x = expo(b, mod - 2);

    if ((x * b) % mod == 1)
    {
        return x;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b, d;
    fact[0] = 1;
    for (int i = 1; i < max; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
    while (cin >> n >> a >> b >> d)
    {
        ll n1 = fact[n];
        ll x = mod_inverse((fact[n - a] * fact[a] % mod));
        ll ans1 = (n1 * x) % mod;

        ll n2 = fact[b];
        ll y = mod_inverse((fact[b - d] * fact[d]) % mod);
        ll ans2 = (n2 * y) % mod;

        ll ans3 = expo(ans2, a);
        ll ans = ((ans1 % mod) * (ans3 % mod)) % mod;
        cout << ans << "\n";
    }
    return 0;
}