#include <bits/stdc++.h>
using namespace std;

int val[1000], wt[1000];
int dp[1000][1000];

int unbounded_knapsack_recursion(int n, int s){
    if (n == 0 || s == 0)
        return 0;

    if (dp[n][s] != -1)
        return dp[n][s];

    if (wt[n - 1] <= s){
        int op1 = unbounded_knapsack_recursion(n, s - wt[n - 1]) + val[n - 1];
        int op2 = unbounded_knapsack_recursion(n - 1, s);
        return dp[n][s] = max(op1, op2);
    }
    else
        return dp[n][s] = unbounded_knapsack_recursion(n - 1, s);
}

int unbounded_knapsack_loop(int n, int s){

    for(int i = 0; i<n; i++){
        for(int j = 0;j<s; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=s; j++){
            if(wt[i-1] <= j){
                int op1 = dp[i][j-wt[i-1]] + val[i-1];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1, op2);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][s];
}

int main()
{
    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    memset(dp, -1, sizeof(dp));
    cout << "Recursion: " << unbounded_knapsack_recursion(n, s) << endl;
    
    memset(dp, 0, sizeof(dp));
    cout << "Loop: " << unbounded_knapsack_loop(n, s) << endl;
    return 0;
}