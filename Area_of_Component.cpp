#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(int si, int sj)
{
    int cmp = 0;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    cmp++;

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                cmp++;
            }
        }
    }
    return cmp;
}
int main()
{
    
    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.')
                cnt++;
        }
    }

    if (cnt == 0)
        cout << -1 << endl;
    else
    {
        int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] != '-')
                {
                    mn = min(mn, bfs(i, j));
                }
            }
        }
        cout << mn << endl;
    }
    return 0;
}
