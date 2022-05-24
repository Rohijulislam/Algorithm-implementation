#include <bits/stdc++.h>
using namespace std;
#define sz 100005
const int k = 20;
int arr[sz], tree[3 * sz];

void create(int n, int s, int e)
{
    if (s == e)
    {
        tree[n] = arr[s];
        return;
    }
    int mid = (s + e) >> 1;
    create(n << 1, s, mid);
    create((n << 1) | 1, mid + 1, e);
    tree[n] = tree[n << 1] + tree[(n << 1) | 1];
}

int query(int n, int s, int e, int i, int j)
{
    if (s > j || e < i)
        return 0;
    if (s >= i && e <= j)
        return tree[n];
    int m = (s + e) >> 1;
    return query(n << 1, s, m, i, j) + query((n << 1) | 1, m + 1, e, i, j);
}

void update(int n, int s, int e, int i, int val)
{
    if (s > i || e < i)
        return;
    if (s == i && e == i)
    {
        // add val
        tree[n] += val;
        return;
    }
    int m = (s + e) >> 1;
    update(n << 1, s, m, i, val);
    update((n << 1) | 1, m + 1, e, i, val);
    tree[n] = tree[n << 1] + tree[(n << 1) | 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m, q, pos, ty, val, l, r;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    create(1, 1, n);

    cin >> q;
    while (q--)
    {
        cin >> ty;
        if (ty == 1)
        {
            // update
            cin >> pos >> val;
            update(1, 1, n, pos, val);
            arr[pos] += val;
        }
        else
        {
            // query
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
