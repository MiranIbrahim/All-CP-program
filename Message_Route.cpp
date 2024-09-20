#include <bits/stdc++.h>
using namespace std;

int n , m;
vector<int> adj[100005];
bool vis[100005];
pair<int,int> parent[100005];
vector<int> path;


void bfs(int src){
    queue <int> q;
    q.push(src);
    vis[src] = true;
    parent[src] = {0,0};

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int child : adj[cur]){
            if(!vis[child]){
                vis[child] = true;
                parent[child] = {cur,parent[cur].second+1};
                q.push(child);
            }
        }
    }

}        

int main() {
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if(!vis[n]) {
        cout << "IMPOSSIBLE"<< endl;
    }
    else{
        int current = n;
        while (current != 0) {
            path.push_back(current);
            current = parent[current].first;
        }
        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int i : path) {
            cout << i << " ";
        }
    }
    
    cout << endl;
    return 0;
    
}