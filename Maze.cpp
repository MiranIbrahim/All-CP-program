#include <bits/stdc++.h>
using namespace std;

int n,m;
bool vis[1005][1005];
vector<pair<int, int>> d = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vector<char> path;
char grid[1005][1005];
pair<int, int> parent[1005][1005];

bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if(grid[a][b] == 'D') {
            return;
        }

        for(int i = 0; i < 4; i++) {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {a, b};

            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si, sj);

    int i = di, j = dj;
    while(i != si || j!=sj){
        if(grid[i][j] != 'D'){
            grid[i][j] = 'X';
        }
        int pi = parent[i][j].first;
        int pj = parent[i][j].second;
        i = pi;
        j = pj;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
