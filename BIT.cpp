/// The code is tested against https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SZ = 200005;
vector<int> v[SZ];
ll BIT[SZ];

void update(int x, int val, int n)
{
    // add val to the postion x

    while (x <= n)
    {
        BIT[x] += val;
        x += x & -x;
    }
}

ll query(int x, int n)
{
    // calculate range sum from 1 to X
    ll sum = 0;
    while (x > 0)
    {
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, n, q, ty, a, b, ans, val, arr[SZ];
    t = 1;

    while (t--)
    {
        cin >> n >> q;
        arr[0] = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> arr[i];
            update(i, arr[i], n);
        }

        while (q--)
        {
            cin >> ty >> a >> b;
            if (ty == 1)
            {
                // update query
                val = b - arr[a];
                arr[a] = b;
                update(a, val, n);
            }
            else
            {
                // range query
                cout << query(b, n) - query(a - 1, n) << "\n";
            }
        }
    }

    return 0;
}