#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const string P = "orbitaxian";
const int P_LEN = P.length();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<vector<long long>> dp(P_LEN + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; ++i) {
            if (s[i] == P[0]) dp[1][i + 1] = 1;
        }

        for (int i = 2; i <= P_LEN; ++i) {
            long long sum = 0;
            for (int j = 1; j <= n; ++j) {
                if (s[j - 1] == P[i - 1]) {
                    dp[i][j] = sum;
                }
                sum += dp[i - 1][j];
                if (j - k >= 1) sum -= dp[i - 1][j - k];
                sum = (sum + MOD) % MOD;
            }
        }

        long long result = 0;
        for (int i = 1; i <= n; ++i) {
            result = (result + dp[P_LEN][i]) % MOD;
        }

        cout << result << '\n';
    }

    return 0;
}
