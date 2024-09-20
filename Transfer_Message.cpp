#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    unordered_set<string> substrings;

    for (int i = 0; i <= N - K; ++i)
    {
        substrings.insert(S.substr(i, K));
    }

    string indicator(K, '0');

    for (int i = 0; i < (1 << K); ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            indicator[j] = ((i >> j) & 1) ? '1' : '0';
        }
        if (substrings.find(indicator) == substrings.end())
        {
            cout << indicator << endl;
            goto next;
        }
    }

    cout << -1 << endl;
next:;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
