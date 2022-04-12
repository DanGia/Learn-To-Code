#include <bits/stdc++.h>
using namespace std;
#define test "sample"
string s;
map<char, bool> letters;
set<pair<char, char>> edges;
vector<string> lines;
vector<vector<char>> a;
vector<char> tp;

void dfs(char c)
{
    letters[c] = true;
    for (char v : a[c])
        if (!letters[v])
            dfs(v);

    tp.push_back(c);
}

int main()
{
    // freopen(test".in","r",stdin);
    // freopen(test".ans","w",stdout);

    while (getline(cin, s))
    {
        // reset
        letters.clear();
        lines.clear();
        a.clear();
        a.resize(300);
        tp.clear();
        edges.clear();

        lines.push_back(s);
        while (getline(cin, s), s.compare("#") != 0)
            lines.push_back(s);

        for (string line : lines)
        {
            assert(line.size() <= 20);
            for (char c : line)
                letters[c] = false;
        }

        for (int i = 1; i < lines.size(); i++)
        {
            string &pre = lines[i - 1];
            string &cur = lines[i];
            for (int j = 0; j < pre.size() && j < cur.size(); j++)
                if (pre[j] != cur[j])
                {
                    if (edges.count(make_pair(pre[j], cur[j])) == 0)
                    {
                        a[pre[j]].push_back(cur[j]);
                        edges.insert(make_pair(pre[j], cur[j]));
                    }
                    break;
                }
        }

        for (auto p : letters)
        {
            char c = p.first;
            bool vs = p.second;
            if (!vs)
                dfs(c);
        }

        for (int i = tp.size() - 1; i >= 0; i--)
            cout << tp[i];
        cout << '\n';
    }

    return 0;
}
