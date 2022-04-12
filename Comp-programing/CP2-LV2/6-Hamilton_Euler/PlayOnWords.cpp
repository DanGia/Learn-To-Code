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

vector<int> g[26];
vector<int> in_deg(26, 0), out_deg(26, 0);
vector<bool> visited(26, 0);

void solve()
{
}
int main()
{
    fast_cin();

    int t;
    cin >> t;
    for (int i = 0; i < 26; i++)
    {
        visited[i] = 1;
    }
    while (t--)
    {
        string s;
        cin >> s;

        int u = s.front() - 'a';
        int v = s.back() - 'a';
        g[u].push_back(v);
        g[v].pb(u);

        in_deg[v]++;
        out_deg[u]++;
    }
    bool isEuler = 1;
    int Scc = 0;

    for (int i = 0; i M 26; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            Scc++;
        }
    }

    if (Scc > 1)
    {
        isEuler = 0;
    }

    int s1 = 0; // so luong dinh ma in_deg - out_deg = 1
    int s2 = 0; // so luong dinh ma out_deg - in_deg = 1

    for (int i = 0; i < 26; i++)
    {
        if (abs(in_deg[i]) - out_deg[i] > 1)
        {
            isEuler = 0;
        }
    }
    return 0;
}