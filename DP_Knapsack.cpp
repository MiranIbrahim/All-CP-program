#include <bits/stdc++.h>
using namespace std;

int weight[100];
int val[100];
int dp[10000][10000];

int knapsack_recursive(int n, int w){

    if (n == 0 || w == 0)
        return 0;

    if (weight[n - 1] <= w){
        // duita kaj
        // (i) niye dekbo ki hoy
        int op1 = knapsack_recursive(n - 1, w - weight[n - 1]) + val[n - 1];

        //(ii) na niye dekhbo ki hoy
        int op2 = knapsack_recursive(n - 1, w);

        return max(op1, op2);
    }
    else{
        // ektai kaj, na niye dekha lagbe ki hoy
        int op2 = knapsack_recursive(n - 1, w);
        return op2;
    }
}

int knapsack_recursive_topDown(int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

    if (weight[n - 1] <= w){
        int op1 = knapsack_recursive_topDown(n - 1, w - weight[n - 1]) + val[n - 1];
        int op2 = knapsack_recursive_topDown(n - 1, w);

        dp[n][w] = max(op1, op2);
        return dp[n][w];
    }
    else{
        int op2 = knapsack_recursive_topDown(n - 1, w);
        dp[n][w] = op2;
        return dp[n][w];
    }
}

int knapsack_loop_bottopTop(int n, int w){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= w; j++){
            if (weight[i - 1] <= j){
                int op1 = dp[i - 1][j - weight[i - 1]] + val[i - 1];
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

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++){
        cin >> weight[i];
    }
    
    for (int i = 0; i < n; i++){
        cin >> val[i];
    }

    cout << "Recursive :" << knapsack_recursive(n , w) << endl;
    cout << "Loop Bottom Top :" << knapsack_loop_bottopTop(n, w) << endl;

    // For recursive TopDown dp needs to initate with -1; this can't be initiated in the recursive function. so it needs to be initiated in the main function;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= w; j++)
            dp[i][j] = -1;
    }
    cout << "Recursive Top Down :" << knapsack_recursive_topDown(n, w) << endl;

    return 0;
}