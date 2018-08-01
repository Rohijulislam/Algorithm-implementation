#include<bits/stdc++.h>
using namespace std;
#define sz 10100

vector<int>tree[sz],cost[sz],edgeindex[sz];
int tarray[sz],tim,chainhead[sz],chainno,chainindex[sz],postarray[sz],depth[sz];
int par[sz][25],subsize[sz],st[sz],ft[sz],otherind[sz],starr[6*sz],root;

int a,b,c,pos=0;

void graph(int n)
{
    for(int i=1; i<n; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        tree[a].push_back(b);
        tree[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
        edgeindex[a].push_back(i);
        edgeindex[b].push_back(i);
    }


}



void dfs(int n,int p,int dp =0)
{
    par[n][0]=p;
    depth[n]=dp;
    subsize[n]=1;
    for(int x=0; x<tree[n].size(); x++)
    {
        if(tree[n][x]==p) continue;
        otherind[edgeindex[n][x]]=tree[n][x];
        dfs(tree[n][x],n,dp+1);
        subsize[n]+=subsize[tree[n][x]];
    }
}

void HLD(int u,int val,int prev)
{
    if(chainhead[chainno]==-1)
        chainhead[chainno]=u;

    chainindex[u]=chainno;
    postarray[u]=pos;
    tarray[pos++]=val;
    int mx =-1,special=-1,ncost;
    for(int i =0; i<tree[u].size(); i++)
    {
        if(tree[u][i]==prev||tree[u][i]==u) continue;

        int k=tree[u][i];
        if(subsize[k]>mx||mx==-1)
        {
            mx=subsize[k];
            special=k;
            ncost=cost[u][i];
        }
    }

    if(special!=-1)
        HLD(special,ncost,u);

    for(int i=0; i<tree[u].size(); i++)
    {
        if(tree[u][i]!=prev && special!=tree[u][i])
        {
            ++chainno;
            HLD(tree[u][i],cost[u][i],u);
        }
    }

}


void stree(int n,int stp,int enp)
{
    if(stp==enp-1)
    {
        starr[n]=tarray[stp];
        return ;
    }
    int mid=(stp+enp)>>1;
    stree(n<<1,stp,mid);
    stree(n*2+1,mid,enp);
    starr[n]=max(starr[n*2],starr[n*2+1]);

}


void update(int n,int stp,int enp,int index,int val)
{
    if(stp>index||enp<=index)
        return ;

    if(stp==index&&enp==stp+1)
    {
        starr[n]=val;
        return ;
    }
    int mid=(stp+enp)>>1;
    update(n<<1,stp,mid,index,val);
    update(n*2+1,mid,enp,index,val);
    starr[n]=max(starr[n*2],starr[n*2+1]);
}


int lca(int u, int v)
{
    if(depth[u] < depth[v]) swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i=0; i<20; i++) if( (diff>>i)&1 ) u = par[u][i];
    if(u == v) return u;
    for(int i=19; i>=0; i--) if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}


int queryres(int n,int stp,int enp,int l,int r)
{

    if(stp>=r||enp<=l)
        return -1;

    if(stp>=l&&enp<=r)
        return starr[n];

    int mid=(stp+enp)>>1;
    return max(queryres(n<<1,stp,mid,l,r),queryres(n*2+1,mid,enp,l,r));

}



int query_up(int u,int v)
{
    if(u==v) return 0;
    int uchain,vchain=chainindex[v],ans=0;
    while(1)
    {
        uchain=chainindex[u];
        if(uchain==vchain)
        {
            if(u==v)
                break;
            int p=queryres(1,0,pos,postarray[v]+1,postarray[u]+1);
            ans=max(ans,p);
            break;
        }

        int p=queryres(1,0,pos,postarray[chainhead[uchain]],postarray[u]+1);
        ans=max(ans,p);
        u=chainhead[uchain];
        u=par[u][0];
    }

    return ans;

}



void query(int u,int v)
{

    int x=lca(u,v);
    int ans=query_up(u,x);
    int res=query_up(v,x);
    printf("%d\n",max(ans,res));

}


void change(int n,int val)
{

    n=otherind[n];
    update(1,0,pos,postarray[n],val);

}


int main()
{
    int n,t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<=n; i++)
        {
            tree[i].clear();
            cost[i].clear();
            edgeindex[i].clear();
            chainhead[i]=-1;
            for(j=0; j<20; j++) par[i][j]=-1;
        }

    for(i=1; i<20; i++)
        for( j=0; j<=n; j++)
                if(par[j][i-1]!=-1)
                    par[j][i] = par[par[j][i-1]][i-1];


        graph(n);
        chainno=0;
        dfs(1,-1);
        HLD(1,-1,-1);
        stree(1,0,pos);

        cout<<"tree\n";

        while(1)
        {
            char s[100];
            scanf("%s",s);
            if(s[0]=='D')
                break;
            scanf("%d %d",&a,&b);
            if(s[0]=='Q')
                query(a,b);
            else
                change(a,b);
        }

    }
    return 0;
}
