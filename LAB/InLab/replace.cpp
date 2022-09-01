#include <iostream>

using namespace std;
void replaceString(string s, string s1, string s2)
{
    int M = s1.length();
    int N = s.length();
    string result;
    int cntTotal, cntIn;
    cntTotal = cntIn = 0;

    for (int i = 0; i < N; i++)
    {
        int j;

        for (j = 0; j < M; j++)
            if (s[i + j] != s1[j] or (i + j >= N))
                break;

        if (j == M)
        {
            cntTotal++;
            continue;
        }
    }

    if (cntTotal == 0)
        cout << s;
    else
    {

        for (int i = 0; i < N; i++)
        {
            int j;

            for (j = 0; j < M; j++)
                if (s[i + j] != s1[j] or (i + j >= N))
                    break;

            if (j == M)
            {
                i = i + j - 1;
                cntIn++;
                if (cntIn == cntTotal)
                    result += s2;
                else
                    result += s1;
                continue;
            }
            else
                result.push_back(s[i]);
        }
    }
    cout << result;
}
int main()
{
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai";
    string s2 = "ong";
    replaceString(s, s1, s2);
}