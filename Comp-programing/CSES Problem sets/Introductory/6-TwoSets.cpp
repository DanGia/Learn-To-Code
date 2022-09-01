#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        vector<int> a, b;
        for (int i = 1; i < n + 1; i++)
        {
            if (i % 4 == 1 || i % 4 == 0)
                a.push_back(i);
            else
                b.push_back(i);
        }
        cout << "YES" << endl;
        cout << a.size() << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << b.size() << "\n";
        for (auto x : b)
            cout << x << " ";
    }
    else if (n % 4 == 3)
    {
        vector<int> a, b;
        for (int i = 1; i < n; i++)
        {
            if (i % 4 == 1 || i % 4 == 2)
                a.push_back(i);
            else
                b.push_back(i);
        }
        b.push_back(n);
        cout << "YES" << endl;
        cout << a.size() << endl;
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        cout << b.size() << "\n";
        for (auto x : b)
            cout << x << " ";
    }
    else
        cout << "NO";
}

int main()
{
    solve();
    return 0;
}