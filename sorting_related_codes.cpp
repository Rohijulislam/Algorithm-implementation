#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

struct Arr
{
    int a, b;
};

bool cmp(Arr ff, Arr ss)
{
    if (ff.a != ss.a)
        return ff.a < ss.a;
    else
        return ff.b < ss.b;
}

void sortVec(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}

int findLowerBound(vector<int> &arr, int val)
{

    if (arr[arr.size() - 1] < val)
        return -1;

    auto it = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

    return it;
}

int findUpperBound(vector<int> &arr, int val)
{
    if (arr[arr.size() - 1] < val)
        return -1;
    auto it = upper_bound(arr.begin(), arr.end(), val) - arr.begin();

    return it;
}

void reverseVec(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
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
        vector<int> arr(n, 0);
        for (i = 0; i < n; i++)
            cin >> arr[i];
    }
    return 0;
}
