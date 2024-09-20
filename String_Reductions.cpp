#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, res;
    cin >> s;
    bool vis[26] = {false};
    
    for(char c:s){
        if(!vis[c-'a']){
            vis[c-'a'] = true;
            res+=c;
        }
    }
    cout << res << endl;
    return 0;
}