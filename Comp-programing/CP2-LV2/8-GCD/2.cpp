#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int j, GCD, LCM;
        cin >> GCD >> LCM;
        if (LCM % GCD == 0) // input = output if b is divisible by a
            cout << GCD << " " << LCM;
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}