#include <bits/stdc++.h>
using namespace std;

int arr[10004];
bool subSetResult(int n, int sum) {
    bool dp[n + 1][sum + 1];
    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j) 
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

             else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

void solve() {
    int n;
    cin >> n;
    int s = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    if (s % 2 == 0) {
        int sum = s / 2;
        if (subSetResult(n, sum)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
