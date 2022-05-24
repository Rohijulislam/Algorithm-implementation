#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long

int blockSize, blockArray[1000];

void buildArray(vector<int> &arr, int n)
{
    int blockIndex = -1;
    blockSize = sqrt(n);
    for (int i = 0; i < n; i++)
    {
        if (i % blockSize == 0)
        {
            blockIndex++;
        }
        blockArray[blockIndex] += arr[i];
    }
}

void update(vector<int> &arr, int index, int value)
{
    int blockNumber = index / blockSize;
    blockArray[blockNumber] += value - arr[index];
    arr[index] = value;
}

int solveQuery(vector<int> &arr, int left, int right)
{
    int sum = 0;
    while (left < right and left % blockSize != 0 and left != 0)
    {
        sum += arr[left];
        left++;
    }
    while (left + blockSize <= right)
    {
        sum += blockArray[left / blockSize];
        left += blockSize;
    }
    while (left <= right)
    {
        sum += arr[left];
        left++;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m, querySize, pos, ty, val, l, r;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "first Query : " << solveQuery(arr, 0, 3) << "\n";
    cout << "second Query : " << solveQuery(arr, 4, 9) << "\n";
    update(arr, 5, 8);
    cout << "third Query : " << solveQuery(arr, 3, 7) << "\n";

    return 0;
}
