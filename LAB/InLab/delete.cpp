#include <bits/stdc++.h>
using namespace std;
void deleteWord(string s, string s1)
{
    int m = s1.length();
    int n = s.length();
    string res;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != s1[j] or ((i + j) >= n))
                break;
        }
        if (j == m)
        {
            i = i + j - 1;
            continue;
        }
        else
            res.push_back(s[i]);
    }
    cout << res;
}
int main()
{
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai ";
    deleteWord(s, s1);
}