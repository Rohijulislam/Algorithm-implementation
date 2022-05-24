#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long
int arr[sz];

struct cal
{
    ll sum, lazy;
} tree[3 * sz];

void create(int n, int s, int e)
{
    if (s == e)
    {
        tree[n].sum = 0;
        tree[n].lazy = 0;
        return;
    }
    int mid = (s + e) >> 1;
    create(n << 1, s, mid);
    create((n << 1) | 1, mid + 1, e);
    tree[n].sum = tree[n << 1].sum + tree[(n << 1) | 1].sum;
    tree[n].lazy = 0;
}

ll query(int n, int s, int e, int i, int j, ll k)
{
    if (s > j || e < i)
        return 0;
    if (s >= i && e <= j)
    {
        return tree[n].sum + ((e - s + 1) * k);
    }
    int m = (s + e) >> 1;
    return query(n << 1, s, m, i, j, k + tree[n].lazy) + query((n << 1) | 1, m + 1, e, i, j, k + tree[n].lazy);
}

void update(int n, int s, int e, int i, int j, ll val)
{
    if (s > j || e < i)
        return;

    if (s >= i && e <= j)
    {
        tree[n].sum += ((e - s + 1) * val);
        tree[n].lazy += val;
        return;
    }
    int mid = (s + e) >> 1;
    update(n << 1, s, mid, i, j, val);
    update((n << 1) | 1, mid + 1, e, i, j, val);
    tree[n].sum = tree[n << 1].sum + tree[(n << 1) | 1].sum + ((e - s + 1) * tree[n].lazy);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m, q, pos, ty, val, l, r;
    cin >> n;
    create(1, 1, n);

    cin >> q;
    while (q--)
    {
        cin >> ty;
        if (ty == 1)
        {
            // update
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
            arr[pos] += val;
        }
        else
        {
            // query
            cin >> l >> r;
            cout << query(1, 1, n, l, r, 0) << "\n";
        }
    }

    return 0;
}
