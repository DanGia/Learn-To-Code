#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define rep(i, e) for (ll i = 0; i < e; i++)
#define REP(i, s, e) for (ll i = s; i < e; i++)
#define rrep(i, s) for (ll i = s; i >= 0; i--)
#define rREP(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define read(a) \
    ll a;       \
    cin >> a

int level[21] = {0};

void primeFactorization(long long n)
{
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {

            // cout << i << " ";
            level[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        level[n]++;
        // cout << n;
    }
}
long long giaiThua(long long n)
{
    if (n == 1)
        return 1;
    return n * giaiThua(n - 1);
}
void solve()
{
}
int main()
{
    fast_cin();
    int a;
    cin >> a;
    long long b = giaiThua(a);
    primeFactorization(b);
    int res = 1;
    for (int i = 2; i <= 20; i++)
    {
        // cout << level[i] << " ";
        if (level[i] != 0)
        {
            res = (res * (level[i] + 1)) % 1000000007;
        }
    }
    cout << res - 1 << endl;
    return 0;
}