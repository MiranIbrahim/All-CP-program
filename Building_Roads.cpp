#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vis[100005];

void dfs(int src){
    vis[src] = true;

    for(int child : adj[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> node;
    for(int i= 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            node.push_back(i);
        }
    }
    cout << node.size()-1 << endl;
    if(node.size()-1){
        for(int i = 1; i<node.size(); i++){
            cout << node[i-1] << " " << node[i] << endl;
        }
    }
    
    return 0;
}