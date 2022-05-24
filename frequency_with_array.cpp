#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int freq[N];

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
            freq[arr[i]]++;
        }
    }
    return 0;
}
