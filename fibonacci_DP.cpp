#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+4;
ll dp[N];

ll fibo_recursive_top_down(int n){
    if(n == 0 || n == 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n]= fibo_recursive_top_down(n-1)+fibo_recursive_top_down(n-2);
}

ll fibo_loop_bottom_up(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
    int n; 
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo_recursive_top_down(n)<< endl;
    cout << fibo_loop_bottom_up(n)<< endl;
    return 0;
}