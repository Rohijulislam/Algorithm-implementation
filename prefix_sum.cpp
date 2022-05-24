#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
        vector<int> arr(n, 0);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i)
                arr[i] += arr[i - 1];
        }
    }
    return 0;
}
