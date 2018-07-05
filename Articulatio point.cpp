#include<bits/stdc++.h>
using namespace std;
#define sz 1009
int ap[sz],par[sz],low[sz],st[sz],tim=0,vis[sz];
vector<int>v[sz];


void dfs(int x)
{
    int i,nb,child=0;
    low[x]=st[x]=++tim;
    vis[x]=1;

    for(i=0; i<v[x].size(); i++)
    {
        nb=v[x][i];
        if(par[x]==nb)
            continue;

        if(!vis[nb])
        {
            child++;
            par[nb]=x;
            dfs(nb);
            low[x]=min(low[x],low[nb]);
            if(par[x]!=-1&&st[x]<=low[nb])
                ap[x]=1;
            if(par[x]==-1&&child>1)
                ap[x]=1;
        }
        low[x]=min(low[x],st[nb]);

    }

    tim++;///finish time

}



int main()
{
    freopen("ap.txt","r",stdin);

    int n,i,j,a,b,num_of_edges;
    scanf("%d",&num_of_edges);
    n=num_of_edges;
    while(n--)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=0; i<sz; i++)
        par[i]=-1;
    dfs(1);

    printf("Articulation points: ");
    for(i=0;i<100;i++)
        if(ap[i]) printf("%d ",i);
    printf("\n");

    return 0;
}
