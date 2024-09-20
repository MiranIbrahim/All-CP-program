#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
const long long INF = 1e18;
long long dis[N];

class Edge {
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool bellmanFord(int n, vector<Edge>& edgeList, int src) {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (Edge& edge : edgeList) {
            int u = edge.u;
            int v = edge.v;
            long long w = edge.w;

            if (dis[u] < INF && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }

    
    for (Edge& edge : edgeList) {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w;

        if (dis[u] < INF && dis[u] + w < dis[v])
            return true; 
    }

    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    while (e--) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edgeList.push_back(Edge(a, b, w));
    }

    int s;
    cin >> s;

    if (bellmanFord(n, edgeList, s)) {
        cout << "Negative Cycle Detected" << endl;
    } else {
        int t;
        cin >> t;
        while (t--) {
            int d;
            cin >> d;
            if (dis[d] == INF)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }

    return 0;
}