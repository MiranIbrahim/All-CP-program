#include <bits/stdc++.h>
using namespace std;
int group_size[1000];
int level[1000];
int parent[1000];
void dsu_initialize(int n){
    for(int i = 0; i<n; i++){
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find_leader(int node){
    if(parent[node] == -1) return node;
    int leader = dsu_find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2){
    int leadA = dsu_find_leader(node1);
    int leadB = dsu_find_leader(node2);
    if(group_size[leadA]>group_size[leadB]){
        parent[leadB] = leadA;
        group_size[leadA] += group_size[leadB];
    }
    else{
        parent[leadA] = leadB;
        group_size[leadB] += group_size[leadA];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    dsu_initialize(n);
    bool cycle = false;
    vector<pair<int, int>> to_remove, to_add;
    while(m--){
        int a,b;
        cin >> a >> b;

        if(dsu_find_leader(a) == dsu_find_leader(b))
            cycle = true;

        else dsu_union_by_size(a, b);
    }
    if(cycle) cout << "cycle found\n";
    else cout << "cycle not found\n";
    return 0;
}