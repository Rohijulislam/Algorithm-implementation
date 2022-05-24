#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    vector<int> tin, low;
    vector<vector<int>> ans;
    vector<int> adj[100005];
    int timer;

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        find_bridges(n, connections);
        return ans;
    }

    void storeBridge(int u, int v)
    {
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        ans.push_back(temp);
    }

    void dfs(int v, int p)
    {
        tin[v] = low[v] = timer++;

        for (int to : adj[v])
        {
            if (to == p)
                continue;
            if (tin[to] != -1)
            {
                low[v] = min(low[v], tin[to]);
            }
            else
            {
                dfs(to, v);
                if (tin[v] < low[to]) // condition to find a bridge
                    storeBridge(v, to);
                low[v] = min(low[v], low[to]);
            }
        }
    }

    void find_bridges(int n, vector<vector<int>> &arr)
    {
        timer = 0;
        tin.assign(n, -1);
        low.assign(n, -1);
        for (auto x : arr)
        {

            int a = x[0];
            int b = x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, -1);
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            // cout<<low[i]<<":: "<<tin[i]<<"\n";
        }
    }
};