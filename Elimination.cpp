#include<bits/stdc++.h>
using namespace std;

bool solve(const string& s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '1' && !st.empty() && st.top() == '0') {
            st.pop(); 
        } else {
            st.push(ch);
        }
    }
    return st.empty();
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (solve(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}