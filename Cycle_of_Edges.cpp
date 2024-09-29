#include <bits/stdc++.h>
using namespace std;

int n , m;
int parent[100005];
int sz[100005];

void dsu_initialize(int n){
    for(int i = 0; i<n; i++){
        parent[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find_parent(int node){
    if(parent[node] == -1)
        return node;    
    return parent[node] = dsu_find_parent(parent[node]);
}

void dsu_union_by_size(int n, int m){
    int a = dsu_find_parent(n);
    int b = dsu_find_parent(m);

    if(sz[a] > sz[b]){
        parent[b] = a;
        sz[a] += sz[b];
        
    }else{
        parent[a] = b;
        sz[b] += sz[a];
    }
}

int main() {
    cin >> n >> m;
    dsu_initialize(n);
    int cnt =0;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(dsu_find_parent(a) == dsu_find_parent(b)){
            cnt++;
        }else{
            dsu_union_by_size(a, b);
        }
    }
    cout << cnt << endl;
    return 0;
}