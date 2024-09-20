#include <bits/stdc++.h>
using namespace std;

using namespace std;
char arr[1003][1003];
bool vis[1003][1003];
vector<pair<int, int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int n, m, di, dj;

bool valid(int p, int q){
    if(p<0 || p>=n || q <0 || q>=m){
        return false;
    }
    return true;
}

bool dfs(int si, int sj){
    if(si == di && sj == dj){
        return true;
    }
    vis[si][sj] = true;
    for(int i = 0; i<4; i++){
        int p=si+d[i].first;
        int q=sj+d[i].second;
        if(valid(p, q) && !vis[p][q] && arr[p][q] == '.'){
            if(dfs(p, q)) 
                return true;   
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    memset(vis, 0, sizeof(vis));

    int si, sj;
    cin >> si >> sj;
    cin >> di >> dj;

    bool ans = dfs(si, sj);
    if(ans)
    cout << "YES\n";
    else cout << "NO\n";

    return 0;
}