#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, m;
int arr[15][15];
int dp[15][15];

ll solve(int i, int j)
{
    if (i == n && j == m)
        return arr[i][j];

    if (i < n && j < m){
        int op1 = solve(i, j + 1);
        int op2 = solve(i + 1, j);
        return arr[i][j] + max(op1, op2);
    }

    else if (i == n)
        return arr[i][j] + solve(i, j + 1);
        
    else
        return arr[i][j] + solve(i + 1, j);
}


int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    ll ans = solve(1, 1);
    cout << ans << endl;
    return 0;
}
