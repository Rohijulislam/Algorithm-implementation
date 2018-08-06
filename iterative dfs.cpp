#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sz 100009
vector<int>v[sz];
int par[sz],st[sz],en[sz],tim=0;

void dfs(int n,int parent)
{
   stack<pii >sk;
   sk.push(make_pair(n,0));
   par[n]=parent;///par[n] holds parent for n node
   while(!sk.empty())
   {
       pii x=sk.top();
       sk.pop();
       cout<<x.first<<"-> ";
       if(x.second==v[x.first].size())
       {
           en[x.first]=++tim;
           cout<<"enase\n";
           continue;
       }

       if(v[x.first][x.second]==par[x.first])
       {
           cout<<v[x.first][x.second]<<"pacase\n";
           sk.push(make_pair(x.first,x.second+1));
       }

       else
       {
           sk.push(make_pair(x.first,x.second+1));
           sk.push(make_pair(v[x.first][x.second],0));
           st[v[x.first][x.second]]=++tim;
           par[v[x.first][x.second]]=x.first;
           cout<<"chase\n";
       }
   }
}




int main()
{
    int n,a,b,i;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);///root pass
    for(i=1;i<=n;i++)
        cout<<st[i]<<" "<<en[i]<<"\n";
}
