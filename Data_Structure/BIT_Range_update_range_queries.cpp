/// The code is tested against https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int SZ = 2e5 + 5;
ll BIT1[SZ], BIT2[SZ];

/// Keep BIT 1 indexed base

// Returns sum of arr[1..index].This function assumes
int getSum(int index, int bitIndex)
{
    ll sum = 0;

    // bitIndex indicates which sum we gonna calculate  BIT1 / BIT2

    // // index in BITree[] is 1 more than the index in arr[]
    // index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        if (bitIndex == 1)
            sum += BIT1[index];
        else
            sum += BIT2[index];

        index -= index & (-index);
    }

    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given
// index in BITree.  The given value 'val' is added to
// BITree[i] and all of its ancestors in tree.
void updateBIT(int n, int index, ll val, int bitIndex)
{
    // bitIndex indicates which sum we gonna BIT we goona consider BIT1 / BIT2

    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        if (bitIndex == 1)
            BIT1[index] += val;
        else
            BIT2[index] += val;

        index += index & (-index);
    }
}

// Returns the sum of array from 1, x]
int sum(int x)
{
    return (getSum(x, 1) * x) - getSum(x, 2);
}

void updateRange(int n,
                 ll val, int l, int r)
{
    // Update Both the Binary Index Trees

    // Update BIT1
    updateBIT(n, l, val, 1);
    updateBIT(n, r + 1, -val, 1);

    // Update BIT2
    updateBIT(n, l, val * (l - 1), 2);
    updateBIT(n, r + 1, -val * r, 2);
}

int rangeSum(int l, int r)
{
    // Find sum from [1,r] then subtract sum
    // from [1,l-1] in order to find sum from
    // [l,r]
    sum(r) - sum(l - 1);
    return sum(r) - sum(l - 1);
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
        // read array & keep 1 based indexing
        // update values into BIT
        // make queries with BIT
        /// reset BIT array
    }

    return 0;
}