#include <bits/stdc++.h>
using namespace std;


char arr[1000][5];

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i<n; i++){
            for(int j = 1; j<=4; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '#'){
                    v.push_back(j);
                }
            }
        }
        
        for(int i = v.size()-1; i>=0; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}