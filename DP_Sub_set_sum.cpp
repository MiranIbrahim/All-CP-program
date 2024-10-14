#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int dp[1000][1000];

int subSetSum_topDown(int n, int s){

    if (n == 0){
        if (s == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (arr[n - 1] <= s){
        int op1 = subSetSum_topDown(n - 1, s - arr[n - 1]);
        int op2 = subSetSum_topDown(n - 1, s);
        return dp[n][s] = op1 + op2;
    }

    else
        return dp[n][s] = subSetSum_topDown(n - 1, s);
}

int subSetSum_bottomUp(int n, int s){
    int dpp[n + 1][s + 1];
    dpp[0][0] = 1;
    for (int i = 1; i <= s; i++)
        dpp[0][i] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= s; j++){
            if (arr[i - 1] <= j)
                dpp[i][j] = dpp[i - 1][j - arr[i - 1]] + dpp[i - 1][j];

            else
                dpp[i][j] = dpp[i - 1][j];
        }
    }
    cout << endl;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=s; j++){
            cout << dpp[i][j] << " ";
        }
        cout << endl;
    }

    return dpp[n][s];
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int s;
    cin >> s;
    memset(dp, -1, sizeof(dp));

    cout << "tpDown: " << subSetSum_topDown(n, s) << endl;
    cout << "bottomUp: " << subSetSum_bottomUp(n, s) << endl;
    return 0;
}