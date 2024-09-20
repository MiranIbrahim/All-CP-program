#include <bits/stdc++.h>
using namespace std;

const int N = 101;
const long long INF = 1e18;
long long dist[N][N];

void floydWarshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;

            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }

    floydWarshall(n);

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (dist[s][d] == INF)
            cout << -1 << endl;
        else
            cout << dist[s][d] << endl;
    }

    return 0;
}