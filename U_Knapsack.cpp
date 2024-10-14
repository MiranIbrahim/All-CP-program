#include <bits/stdc++.h>
using namespace std;

int weight[101];
int val[101];


int knapsack(int n, int w){
    if(n == 0 || w == 0)
        return 0;
    
    if(weight[n-1] <= w){
        int op1 = knapsack(n-1, w-weight[n-1]) + val[n-1];
        int op2 = knapsack(n-1, w);
        return max(op1, op2);
    }
    else{
        int op2 = knapsack(n-1, w);
        return op2;
    }
}

int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++){
        cin >> weight[i] >> val[i];
    }
    cout << knapsack(n, w) << endl;

    return 0;
}