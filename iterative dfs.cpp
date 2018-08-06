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
   st[n]=++tim;
   par[n]=parent;  ///par[n] holds parent for n node
   while(!sk.empty())
   {
       pii x=sk.top();
       sk.pop();
       if(x.second==v[x.first].size())
       {
           en[x.first]=++tim;/// all children are taken
           continue;
       }

       if(v[x.first][x.second]==par[x.first])
       {
           sk.push(make_pair(x.first,x.second+1));///  ignoring  parent
       }

       else
       {
           sk.push(make_pair(x.first,x.second+1));
           sk.push(make_pair(v[x.first][x.second],0)); ///new child
           st[v[x.first][x.second]]=++tim;
           par[v[x.first][x.second]]=x.first;
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
