#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> v[N];
bool vis[N];
int dis1[N];
int dis2[N];

void bfs(int src, int op){
    queue <int> q;
    q.push(src);
    vis[src] = true;

    if(op == 1) dis1[src] = 0;
    else dis2[src] = 0;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int child: v[parent]){

            if(!vis[child]){
                q.push(child);
                vis[child] = true;

                if(op == 1) dis1[child] = dis1[parent]+1;
                else dis2[child] = dis2[parent]+1;
            }
        }
    }
}

int main() {
    int t; 
    cin >> t;
    int cs = 1;
    while(t--){
        int n, m;
        cin >> n >> m;
        while(m--){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int s, d;
        cin >> s >> d;
        for(int i = 0; i<n; i++){
            vis[i] = false;
            dis1[i] = -1;
        }
        bfs(s,1);

        for(int i = 0; i<n; i++){
            vis[i] = false;
            dis2[i] = -1;
        }
        bfs(d,2);

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int val = dis1[i] + dis2[i];
            ans = max(ans, val);
        }

        cout << "Case " << cs++ << ": " << ans << endl;

        for (int i = 0; i < n; i++)
            v[i].clear();
    }
    return 0;
}