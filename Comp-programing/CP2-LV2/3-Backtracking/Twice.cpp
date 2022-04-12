#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Given a positive integer UU, find the largest integer LL such that L \leq UL≤U and LL does not contain any digit more than twice.

vector<int> cnt(10, 0);
bool ok = false;
string curr_value, result;

void backtracking(string &s, int idx, bool isSmaller)
{
    if (ok)
        return;

    if (idx == s.size())
    {
        result = curr_value;
        ok = true;
        return;
    }

    char x = s[idx];
    if (isSmaller)
    {
        x = '9';
    }
    for (char i = x; i >= '0' && !ok; i--)
    {
        if (cnt[i - '0'] < 2)
        {
            cnt[i - '0']++;
            curr_value.push_back(i);
            backtracking(s, idx + 1, isSmaller | (i < s[idx]));
            curr_value.pop_back();
            cnt[i - '0']--;
        }
    }
}
int main()
{
    string s;
    while (cin >> s)
    {
        curr_value.clear();
        ok = false;
        backtracking(s, 0, 0);

        reverse(result.begin(), result.end());
        while (result.back() == '0')
        {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        cout << result << endl;
    }
    return 0;
}