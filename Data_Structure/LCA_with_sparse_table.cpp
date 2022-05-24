#include <bits/stdc++.h>
using namespace std;
#define sz 100005
const int k = 20;
int par[sz][k + 1], level[sz], link[sz];
vector<pair<int, int>> v[sz];

void dfs(int n, int p, int lev = 0)
{
    par[n][0] = p;
    level[n] = lev;
    for (auto x : v[n])
    {
        if (x.first != p)
        {
            link[x.first] = link[n] + x.second;
            dfs(x.first, n, lev + 1);
        }
    }
}

void sparse(int n)
{
    for (int j = 1; j < 18; j++)
        for (int i = 1; i <= n; i++)
            if (par[i][j - 1])
                par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int u, int v)
{

    if (level[u] < level[v])
        swap(u, v);
    for (int i = 17; i >= 0; i--)
    {
        if (level[u] - (1 << i) >= level[v])
            u = par[u][i];
    }

    if (u == v)
        return u;

    for (int i = 17; i >= 0; i--)
    {
        if (par[u][i] && par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int main()
{
    int n, q, i, a, b, c, dist;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(make_pair(b, 1));
        v[b].push_back(make_pair(a, -1));
    }

    dfs(1, 0);
    sparse(n);
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
