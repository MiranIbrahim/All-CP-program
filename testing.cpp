#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<pair<int, int> > v[N];
int dis[N];

class cmp
{

public:
    bool operator()(pair<int, int>a, pair<int, int> b){
        return a.second > b.second;
    }
};


void dijkastra(int src){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty()){
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for(pair<int, int> child : v[node]){
            int childNode = child.first;
            int childCost = child.second;
            if(cost+childCost < dis[childNode]){
                dis[childNode] = cost+childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
    
}
int main() {
    
    return 0;
}