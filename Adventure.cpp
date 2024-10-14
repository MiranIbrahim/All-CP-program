#include <bits/stdc++.h>
using namespace std;

int wt[10000];
int val[10000];
int dp[10000][10000];

int knapsack_loop_bottopTop(int n, int w){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++){
            if (wt[i - 1] <= j){
                int op1 = dp[i - 1][j - wt[i - 1]] + val[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else{
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }
    return dp[n][w];
}

void solve(){
    int n, w;
    cin >> n >> w;
    for(int i = 0; i< n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i< n; i++){
        cin >> val[i];
    }
    cout << knapsack_loop_bottopTop(n, w) << endl;
}
int main() {
    int t; 
    cin >> t; while(t--)   
    solve();
    return 0;
}