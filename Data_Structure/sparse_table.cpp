// query sparse matrix for SUM/Max/Min/GCD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SZ = 200005;
const int k = 20;
ll table[SZ][k + 1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, i, j, n, q, ty, a, b, ans, val;
    t = 1;

    while (t--)
    {
        cin >> n; // array size
        vector<int> arr(n, 0);
        for (i = 0; i < n; i++)
            cin >> arr[i];

        // build Sparse Table
        for (i = 0; i < n; i++)
            table[i][0] = arr[i];

        for (j = 1; j <= k; j++)
        {
            for (i = 0; i <= n - (1 << j); i++)
                table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
        }

        cin >> q; // number of queries
        while (q--)
        {
            cin >> a >> b; // range
            ll sum = 0;
            for (j = k; j >= 0; j--)
            {
                if (a + (1 << j) - 1 <= b)
                {
                    sum += table[a][j];
                    a += 1 << j; // instead of having a', we increment a directly
                }
            }

            cout << sum << "\n";
        }
    }

    return 0;
}