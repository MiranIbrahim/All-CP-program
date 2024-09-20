void dsu_union_by_level(int node1, int node2)
// {
//     int leaderA = dsu_find(node1);
//     int leaderB = dsu_find(node2);
//     if (level[leaderA] > level[leaderB])
//     {
//         par[leaderB] = leaderA;
//     }
//     else if (level[leaderB] > level[leaderA])
//     {
//         par[leaderA] = leaderB;
//     }
//     else
//     {
//         par[leaderA] = leaderB;
//         level[leaderB]++;
//     }
// }