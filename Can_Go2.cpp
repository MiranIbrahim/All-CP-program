#include <bits/stdc++.h>
using namespace std;
char arr[1003][1003];
bool vis[1003][1003];
vector<pair<int, int>> d = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int n, m;


bool valid(int p, int q){
    if(p<0 || p>=n || q <0 || q>=m){
        return false;
    }
    return true;
}

bool dfs(int x, int y){
    if(arr[x][y] == 'B'){
        return true;
    }
    vis[x][y] = true;
    for(int i = 0; i<4; i++){
        int p=x+d[i].first;
        int q=y+d[i].second;
        if(valid(p, q) && !vis[p][q] && arr[p][q] != '#'){
            if(dfs(p, q)) 
                return true;   
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    int x,y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'A'){
                x = i;
                y = j;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    bool ans = dfs(x, y);
    if(ans)
    cout << "YES\n";
    else cout << "NO\n";
    return 0;
}