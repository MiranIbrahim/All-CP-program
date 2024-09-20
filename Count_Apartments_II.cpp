#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[1003][1003];
bool vis[1003][1003];
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> rooms;

bool valid(int p, int q) {
    return (p >= 0 && p < n && q >= 0 && q < m);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int room = 1;  

    for (int i = 0; i < 4; i++) {
        int p = x + d[i].first;
        int q = y + d[i].second;
        if (valid(p, q) && !vis[p][q] && arr[p][q] == '.') {
            room += dfs(p, q);  
        }
    }
    return room;
}

void count() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.' && !vis[i][j]) {
                int totalRoom = dfs(i, j);  
                rooms.push_back(totalRoom);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    }

    memset(vis, 0, sizeof(vis));

    count();
    if (rooms.empty()) 
        cout << 0 << endl;
    
    else {
        sort(rooms.begin(), rooms.end());
        for (int i : rooms) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
