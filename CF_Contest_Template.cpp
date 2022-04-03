#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (!!(x & (1LL << k)))
#define mod 998244353
const int SZ = 200005;
vector<int> v[SZ];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, j, a, b, l, r, ans, arr[SZ];
    string s;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];

        for (i = 0; i < n; i++)
        {
        }

        cout << ans << "\n";
    }

    return 0;
}