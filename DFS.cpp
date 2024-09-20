#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
bool vis[1000];

void dfs(int src){
    vis[src] = true;
    cout << src << endl;

    for(int child : adj[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
    return 0;
}