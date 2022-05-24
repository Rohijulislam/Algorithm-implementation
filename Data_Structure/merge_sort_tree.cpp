#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int sz = 2e5 + 5;

ll arr[sz];
vector<ll> tree[4 * sz];

void build(int l, int r, int node)
{
    if (l == r)
    {
        tree[node].push_back(arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    int left = 2 * node, right = 2 * node + 1;
    build(l, mid, left);
    build(mid + 1, r, right);

    merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

int query(int cur, int l, int r, int x, int y, int k)
{
    if (r < x || l > y)
    {
        return 0; // out of range
    }
    if (x <= l && r <= y)
    {
        // Binary search over the current sorted vector to find elements smaller than K

        return lower_bound(tree[cur].begin(), tree[cur].end(), k) - tree[cur].begin();
    }
    int mid = l + (r - l) / 2;
    return query(2 * cur + 1, l, mid, x, y, k) + query(2 * cur + 2, mid + 1, r, x, y, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m, querySize, pos, ty, val, l, r;
    cin >> n;
    build(1, n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> querySize;
    while (querySize--)
    {
        cin >> l >> r >> val;
        cout << query(1, 1, n, l, r, val) << "\n";
    }

    return 0;
}
