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

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int N;                               // Number of nodes
vector<int> graph[100000], top_sort; // Assume that this graph is a DAG
bool visited[100000];

void dfs(int node)
{
    for (int i : graph[node])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    top_sort.pb(node);
}

void compute()
{
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    reverse(begin(top_sort), end(top_sort));
    // The vector `top_sort` is now topologically sorted
}

int main()
{
    int M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].pb(b - 1);
    }
    compute();
    vector<int> ind(N);
    for (int i = 0; i < N; i++)
        ind[top_sort[i]] = i;
    for (int i = 0; i < N; i++)
        for (int j : graph[i])
            if (ind[j] <= ind[i])
            {
                cout << "IMPOSSIBLE\n"; // topological sort wasn't valid
                exit(0);
            }
    for (int i : top_sort)
        cout << i + 1 << " ";
    cout << "\n";
}