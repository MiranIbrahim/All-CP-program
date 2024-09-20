#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> vis[n];
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        vis[x].push_back(x);
        vis[x].push_back(y);
        vis[y].push_back(y);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        bool flag = false;
        for (int node:vis[a])
        {
            if (node == b)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}