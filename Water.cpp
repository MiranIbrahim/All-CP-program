#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n+1];
    int cp[n+1];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        cp[i] = arr[i];
    }

    sort(cp, cp+n);
    set<int> st;
    for(int i = 0; i<n; i++){
        if(arr[i] == cp[n-1]){
            st.insert(i);
        }
        if(arr[i] == cp[n-2]){
            st.insert(i);
        }
    }
    
    for(int i :st){
        cout << i << " ";
    }
    cout << endl;
    
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
