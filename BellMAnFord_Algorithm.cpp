#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
long long dis[N];  

class Edge
{

public:
    int u, v, w;
    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void bellManFord(int n, vector<Edge> edgeList, int src){
    for(int i = 1; i<=n; i++){
        dis[i] = INT_MAX;
    }
    dis[src] = 0;

    for(int i = 1; i<=n-1; i++){
        for(Edge edge : edgeList){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if(dis[u] < INT_MAX && dis[u]+w < dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector <Edge> edgeList;
    while(e --){
        int a, b, w;
        cin >> a >> b >> w;
        edgeList.push_back(Edge(a, b, w));
    }
    bellManFord(n, edgeList, 1);

    for(int i = 1; i<=n; i++){
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}