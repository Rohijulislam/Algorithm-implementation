#include<bits/stdc++.h>
using namespace std;
#define sz 100009
int arr[sz];

struct node
{
    node *left,*right;
    int val;
    node()
    {
        left=NULL;
        right=NULL;
        val=0;
    }
}*root[sz];


void build (node *n, int s,int e)
{

    if(s==e)
    {
        n->val=arr[s];
        return ;
    }

    int m=(s+e)>>1;
    n->left=new node();
    n->right=new node();
    build(n->left,s,m);
    build(n->right,m+1,e);
    n->val=n->left->val+ n->right->val;

}


int query(node *n,int s,int e,int i,int j)
{

   if(s>j||e<i)
    return 0;

   if(s>=i&&e<=j)
       return n->val;

     int m=(s+e)>>1;
     return query(n->left,s,m,i,j)+query(n->right,m+1,e,i,j);

}


void update(node *cur,node *pre,int s,int e,int pos,int val)
{

    if(s>pos||e< pos)
        return ;


    if(s==e&&s==pos)
    {

        cur->val+=val;
        return ;
    }


    int m=(s+e)>>1;

    if(m>=pos)
    {
        cur->right=pre->right;
        cur->left=new node();
    }

    else
    {
        cur->left=pre->left;
        cur->right=new node();
    }

      update(cur->left,pre->left,s,m,pos,val);
      update(cur->right,pre->right,m+1,e,pos,val);

      cur->val=cur->left->val+ cur->right->val;
}




int main()
{
    int n,i,pk;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&arr[i]);



    root[0]= new node();
    build(root[0],1,n);///root[0], root node  of  first segment tree

    pk=query(root[0],1,n,2,4);  /// sum of 2 to 4 positions before any update
    printf("Before update : %d\n",pk);
    root[1]=new node(); ///root[1],root node  of  2nd segment tree


    update(root[1],root[0],1,n,3,5);///update 3 position value as 5
    pk=query(root[1],1,n,2,4);///sum of 2 to 4 positions  after update
    printf("After update : %d\n",pk);



    return 0;
}
