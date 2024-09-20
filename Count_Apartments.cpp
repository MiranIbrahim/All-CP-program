#include <bits/stdc++.h>
using namespace std;

char arr[1003][1003];
bool vis[1003][1003];
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;

int cnt = 0;
bool valid(int p, int q){
    if(p<0 || p>=n || q <0 || q>=m){
        return false;
    }
    return true;
}
void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int p = x + d[i].first;
        int q = y + d[i].second;
        if (valid(p, q) && !vis[p][q] && arr[p][q] == '.') {
            dfs(p, q);
        }
    }
}

int count(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    memset(vis, 0, sizeof(vis));
    
    cout << count() << endl;

    return 0;
}
