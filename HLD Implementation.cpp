/*
code was tested on
https://www.spoj.com/problems/QTREE/
*/

#include<bits/stdc++.h>
using namespace std;
#define N 10100

vector <int>adj[N], costs[N],edge[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], par[20][N], edgeid[N], subsize[N];
int tree[N*4];


void create(int n, int s, int e)
{
    if(s == e)
    {
        tree[n] = baseArray[s];
        return;
    }
    int c1 = (n<<1), m = (s+e)>>1;
    create(c1, s, m);
    create(c1+1, m+1, e);
    tree[n] =max(tree[c1],tree[c1+1]);
}


void update(int n, int s, int e, int l, int val)
{
    if(s > l || e <l) return;
    if(s == l && s == e)
    {
        tree[n] = val;
        return;
    }
    int c1 = (n<<1), m = (s+e)>>1;
    update(c1, s, m, l, val);
    update(c1+1, m+1, e, l, val);
    tree[n] =max(tree[c1],tree[c1+1]);
}


int query(int n, int s, int e, int l, int r)
{
    if(s > r || e <l)
        return 0;

    if(s >= l && e <= r)
        return tree[n];

    int c1 = (n<<1), m = (s+e)>>1;
    int p1=query(c1, s, m, l, r);
    int p2=query(c1+1, m+1, e, l, r);
    return max(p1,p2);
}



int query_up(int u, int v)
{
    if(u == v) return 0;
    int uchain, vchain = chainInd[v], ans = -1;

    while(1)
    {
        uchain = chainInd[u];
        if(uchain == vchain)
        {

            if(u==v) break;
            int k=query(1, 1, ptr, posInBase[v]+1, posInBase[u]);
            ans=max(ans,k);
            break;
        }
        int k=query(1, 1, ptr, posInBase[chainHead[uchain]], posInBase[u]);
        ans=max(ans,k);

        u = chainHead[uchain];
        u=par[0][u];
    }
    return ans;
}


int LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i=0; i<20; i++) if( (diff>>i)&1 ) u = par[i][u];
    if(u == v) return u;
    for(int i=19; i>=0; i--) if(par[i][u] != par[i][v])
        {
            u = par[i][u];
            v = par[i][v];
        }
    return par[0][u];
}

void query(int u, int v)
{

    int lca = LCA(u, v);
    int ans = query_up(u, lca);
    int temp = query_up(v, lca);
    if(temp > ans) ans = temp;
    printf("%d\n", ans);
}



void change(int i, int val)
{
    int u = edgeid[i];
    update(1, 1, ptr, posInBase[u], val);
}


void HLD(int curNode, int cost, int prev)
{
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = curNode;

    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;
    baseArray[ptr++] = cost;

    int mx=-1,sc = -1, ncost;

    for(int i=0; i<adj[curNode].size(); i++)
    {
     int k=adj[curNode][i];
        if(mx< subsize[k]&&k!=prev)
        {
            mx=subsize[k];
            sc =k;
            ncost = costs[curNode][i];
        }
    }


    if(sc != -1)
        HLD(sc, ncost, curNode);

    for(int i=0; i<adj[curNode].size(); i++)
    {
        int k=adj[curNode][i];
        if(sc != k&&k!=prev)
        {
            chainNo++;
            HLD(k, costs[curNode][i], curNode);
        }
    }
}


void dfs(int cur, int prev, int lev=0)
{
    par[0][cur] = prev;
    depth[cur] = lev;
    subsize[cur] = 1;
    for(int i=0; i<adj[cur].size(); i++)
        if(adj[cur][i] != prev)
        {
            edgeid[edge[cur][i]] = adj[cur][i];
            dfs(adj[cur][i], cur, lev+1);
            subsize[cur] += subsize[adj[cur][i]];
        }
}


int main()
{
    int t,i,j;
    scanf("%d ", &t);
    while(t--)
    {
        ptr = 1;
        int n;
        scanf("%d", &n);

        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            costs[i].clear();
            edge[i].clear();
            chainHead[i] = -1;
            for(int j=0; j<20; j++) par[j][i] = -1;
        }
        for(i=1; i<n; i++)
        {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);

            adj[u].push_back(v);
            costs[u].push_back(c);
            edge[u].push_back(i);
            adj[v].push_back(u);
            costs[v].push_back(c);
            edge[v].push_back(i);
        }

        chainNo = 0;
        dfs(1, 1);
        HLD(1, 0, 1);
        create(1, 1, ptr);


        for(i=1; i<20; i++)
            for(j=0; j<=n; j++)
                if(par[i-1][j] != -1)
                    par[i][j] = par[i-1][par[i-1][j]];


        while(1)
        {
            char s[10];
            scanf("%s", s);
            if(s[0]=='D')
                break;

            int a, b;
            scanf("%d %d", &a, &b);
            if(s[0]=='Q')
                query(a, b);
            else
                change(a, b);
        }
    }
}
