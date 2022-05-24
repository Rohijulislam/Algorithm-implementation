#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
vector<int> tree[N];

void dfs(int n, int p)
{
    for (auto child : tree[n])
    {
        if (child == p)
            continue;

        dfs(child, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        dfs(1, 1);
    }
    return 0;
}
