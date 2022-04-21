#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int test;

    scanf("%d\n", &test);
    while (test--)
    {

        ll n = 0;

        string str;
        ll num[100] = {0};

        getline(cin, str);
        // cin >> str;
        ll tmp = 0;
        ll size = str.length();

        for (ll i = 0; i < size; i++)
        {

            if (isdigit(str[i]))

                tmp = tmp * 10 + (int)(str[i] - '0');
            // convert to int
            else
            {

                if (tmp > 0)
                {
                    num[n++] = tmp;
                    tmp = 0;
                }
            }
        }

        if (tmp != 0)
            num[n++] = tmp;
        if (n == 1)
        {
            cout << num[n - 1] << endl; // end
            continue;
        }
        sort(num, num + n);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ll temp = gcd(num[j], num[i]);
                res = (res > temp) ? res : temp;
            }
        }
        cout << res << endl;
    }

    return 0;
}