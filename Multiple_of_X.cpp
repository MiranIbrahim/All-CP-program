#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long int x, n;
        cin >> x >> n;
        if(x <= 0 || x > n){
            cout << "Invalid!\n";
        }
        else{
            for(long long int i = 1; i<=(n/x); i++){
                cout << x * i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}