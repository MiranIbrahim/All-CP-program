#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int, int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
char dir[4] = {'R', 'L', 'D', 'U'};
pair<int, int> parent[1005][1005];

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};
    
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if(grid[a][b] == 'B') {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {a,b};
            }
        }
    }
    return false;
}
string get_path (int si, int sj, int di, int dj){
    int ci = di, cj = dj;
    string path = "";

    while(ci!=si || cj!=sj){
        int pi = parent[ci][cj].first;
        int pj = parent[ci][cj].second;

        for(int i = 0; i<4; i++){
            if(pi+d[i].first == ci && pj+d[i].second == cj){
                path+=dir[i];
                break;
            }
        }
        ci = pi; cj = pj;
    }
    reverse(path.begin(), path.end());
    return path;
}


int main() {
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    int si, sj, di, dj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                si = i; sj = j;
            }
            if(grid[i][j] == 'B') {
                di = i; dj = j;
            }
        }
    }

    if(bfs(si, sj)) {
        string path = get_path(si, sj, di, dj);
        cout << "YES\n" << path.length() << "\n" << path << "\n";        
    }
    else cout << "NO\n";

    return 0;
}