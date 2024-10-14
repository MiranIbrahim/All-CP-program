#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n;
ll dp[100005];

bool solve(ll x)
{
    if (x == n) 
        return true;
    if (x > n) 
        return false;
    
    if (dp[x] != -1) 
        return dp[x];
    
    dp[x] = solve(x + 3) || solve(x * 2);
    return dp[x];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
    
        for (ll i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        
        bool ans = solve(1); 
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
