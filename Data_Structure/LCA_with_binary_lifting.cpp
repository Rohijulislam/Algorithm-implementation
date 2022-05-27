#include <bits/stdc++.h>
using namespace std;
#define sz 100005
const int k = 20; // k should be >= ceil(log2(nodes_Count))
int up[sz][k + 1];
vector<int> adj[sz];
int timer;
vector<int> tin, tout;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= k; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = k; i >= 0; --i)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root, int n)
{
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    memset(up, 0, sizeof(up));
    dfs(root, root);
}

int main()
{
    int n, q, i, a, b, c, dist;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    preprocess(1, n + 2);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &a, &b);
        if (a == b)
        {
            printf("Yes\n");
            continue;
        }
        c = lca(a, b);
        cout << c << "\n";
    }
    return 0;
}
