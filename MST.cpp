#include <bits/stdc++.h>
using namespace std;

int parent[100005];
int group_size[100005];

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
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

void dsu_inintialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find_leader(int node)
{
    if (parent[node] == -1)
        return node;

    int leader = dsu_find_leader(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leadA = dsu_find_leader(node1);
    int leadB = dsu_find_leader(node2);

    if (group_size[leadA] > group_size[leadB])
    {
        parent[leadB] = leadA;
        group_size[leadA] += group_size[leadB];
    }
    else
    {
        parent[leadA] = leadB;
        group_size[leadB] += group_size[leadA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu_inintialize(n);
    vector<Edge> edgeList;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    sort(edgeList.begin(), edgeList.end(), cmp);

    long long int cost = 0;
    
    for (Edge edge : edgeList)
    {
        if (dsu_find_leader(edge.u) == dsu_find_leader(edge.v))
        {
            continue;
        }
        else
        {
            dsu_union_by_size(edge.u, edge.v);
            cost+=edge.w;
        }
    }
    int grp = 0;
    for(int i =0; i<n; i++)
        if(parent[i]== -1) grp++;
    if(grp<2){
        cout << cost;
    }else cout << "IMPOSSIBLE";
    cout << endl;
    
    return 0;
}