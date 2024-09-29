#include <bits/stdc++.h>
using namespace std;

int parent[10000];
int group_size[10000];
int level[10000];

void dsu_initialize(int n){
    for(int i = 0; i<n; i++){
        parent[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find_leader(int node){
    if(parent[node] == -1)
        return node;
    
    return parent[node] = dsu_find_leader(parent[node]);
}

void dsu_union_by_size(int node1, int node2){
    int leaderA = dsu_find_leader(node1);
    int leaderB = dsu_find_leader(node2);

    if(group_size[leaderA] > group_size[leaderB]){
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main() {
    int n;
    cin >> n;
    dsu_initialize(n);
    vector<pair<int, int>> to_remove, to_add;
    int m = n-1;
    
    while(m--){
        int a,b;
        cin >> a >> b;

        if(dsu_find_leader(a) == dsu_find_leader(b))
            to_remove.push_back({a, b});
        else dsu_union_by_size(a, b);
    }
    
    for(int i = 2; i<=n; i++){
        if(dsu_find_leader(i) != dsu_find_leader(1)){
            to_add.push_back({1, i});
            dsu_union_by_size(1, i);
        }
    }

    cout << to_add.size() << endl;
    for (int i = 0; i < to_add.size(); i++) {
        cout << to_remove[i].first << " " << to_remove[i].second << " ";
        cout << to_add[i].first << " " << to_add[i].second << endl;
    }
    return 0;
}