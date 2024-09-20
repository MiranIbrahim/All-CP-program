#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
vector<pair<int, int>> v[N];
long long dis[N];  

class cmp {
public:
    bool operator()(pair<int, long long> a, pair<int, long long> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty()) {
        pair<int, long long> parent = pq.top();
        pq.pop();
        int node = parent.first;
        long long cost = parent.second;
        // if (cost > dis[node]) continue;  
        for (pair<int, int> child : v[node]) {
            int childNode = child.first;
            long long childCost = child.second;
            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while (e--) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }

    for (int i = 1; i <= n; i++) {  
        dis[i] = INT_MAX;  
    }

    int s;
    cin >> s;
    dijkstra(s);

    int t;
    cin >> t;
    while (t--) {
        int d;
        long long dw;  
        cin >> d >> dw;
        if (dis[d] <= dw) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}