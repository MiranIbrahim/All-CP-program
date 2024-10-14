#include<bits/stdc++.h>
using namespace std;

int main(){
    stack <int> stk;
    queue <int> q;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        stk.push(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    
    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    bool same = true;
    while (!stk.empty() && !q.empty()) {
        if (stk.top() != q.front()) {
            same = false;
            break;
        }
        stk.pop();
        q.pop();
    }

    if (same && stk.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}