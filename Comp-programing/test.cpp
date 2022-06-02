#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        int k;
        cin >> k;
        if (k == 1)
            cout << "YES\n";
        else if (k == 2)
        {
            if ((n[n.length() - 1] - '0') % 2 == 0)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
        else if (k == 3)
        {
            ll sum = 0;
            for (ll i = 0; i < n.length(); i++)
            {
                sum += (n[i] - '0');
            }
            // cout << sum << endl;
            if ((sum % 3 == 0) && ((n[n.size() - 1] - '0') % 2 == 0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}