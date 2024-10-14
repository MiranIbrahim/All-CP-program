#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n;

bool solve(ll x)
{
    if (x == n)
        return true;

    if (x > n)
        return false;

    return solve(x * 10) || solve(x * 20);
}

bool solve2(ll x){
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool ans = solve(1);
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}