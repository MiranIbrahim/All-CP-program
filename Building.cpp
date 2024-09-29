#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int sz[100005];

class Edge
{
public:
    int u, v;
    long long int w;

    Edge(int u, int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find_parent(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find_parent(parent[node]);
}

void dsu_union_by_size(int n, int m)
{
    int a = dsu_find_parent(n);
    int b = dsu_find_parent(m);

    if (sz[a] > sz[b])
    {
        parent[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        parent[a] = b;
        sz[b] += sz[a];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);
    vector<Edge> edgeList;

    while (e--)
    {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);

    long long int cost = 0;
    int node = 0;
    for (Edge x : edgeList)
    {
        if (dsu_find_parent(x.u) == dsu_find_parent(x.v))
            continue;
        else
        {
            dsu_union_by_size(x.u, x.v);
            cost += x.w;
            node++;
        }
    }
    if (node == n - 1)
        cout << cost << endl;
    else
        cout << -1 << endl;
    return 0;
}