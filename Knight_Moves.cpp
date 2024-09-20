#include <bits/stdc++.h>
using namespace std;

int n, m, qi, qj;
int dis[105][105];
bool mat[105][105];
vector<pair<int, int>> d = {{-2, -1}, {-2, +1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool valid(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

int bfs(int ki, int kj){
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int>> q;
    q.push({ki, kj});
    dis[ki][kj] = 0;

    while (!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if(a == qi && b == qj)
            return dis[a][b];

        for (int i = 0; i < 8; i++){
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && dis[ci][cj] == -1){
                q.push({ci, cj});
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        cin >> qi >> qj;
        cout << bfs(ki, kj) << endl;
    }
    return 0;
}