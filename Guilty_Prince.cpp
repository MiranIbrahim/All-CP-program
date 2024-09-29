#include <bits/stdc++.h>
using namespace std;

int n, m,cnt;
char grid[100][100];
bool vis[100][100];
int dis[100][100];
vector<pair <int, int>> d = {{0,1}, {0, -1},{1, 0}, {-1, 0}};

bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int si, int sj){
    vis[si][sj] = true;
    cnt++;
    
    for(int i = 0; i<4; i++){
        int ci = si+d[i].first;
        int cj = sj+d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#'){
            dfs(ci,cj);
        }
    }
}

int main() {
    int t; 
    cin >> t;
    int x = 1;
    while(t--){
        cin >> m >> n;
        int si, sj;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == '@'){
                   si = i;
                    sj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        cnt = 0;
        dfs(si, sj);
        
        cout << "Case " << x++ << ": " << cnt << endl;
    }
    return 0;
}



