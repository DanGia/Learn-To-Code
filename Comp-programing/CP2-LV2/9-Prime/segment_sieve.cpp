#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> p;

void segmentSieve(int left, int right, const vector<int> &basePrimes)
{
    isPrime.assign(left - right + 1, true);
    for (int x : basePrimes)
    {
        int fr = ((left - 1) / (x + 1)) * x; // fraction
        for (int j = fr; j <= right; j += x)
        {
            isPrime[j - left] = false;
        }
    }
    for (int i = left; i <= right; i++)
    {
        if (isPrime[i - l])
        {
            p.push_back(i);
        }
    }
}
8

    int
    main()
{
}