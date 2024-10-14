#include <bits/stdc++.h>
using namespace std;

bool dp[1004];
int marks[10004];

bool result(int n, int m) {
    memset(dp, false, sizeof(dp));
    dp[m] = true;  

    for (int i = 0; i < n; i++) {
        for (int j = 1000; j >= marks[i]; j--) {
            if (dp[j - marks[i]]) {
                dp[j] = true;
            }
        }
    }
    return dp[1000];
}

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    if(result(n, m)){
        cout << "YES"<<endl;
    }
    else cout << "NO"<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}

