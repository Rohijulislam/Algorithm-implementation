#include <bits/stdc++.h>
using namespace std;
#define sz 100005
#define ll long long
void remove(int idx); // TODO: remove value at idx from data structure
void add(int idx);    // TODO: add value at idx from data structure
int get_answer();     // TODO: extract the current answer of the data structure

int block_size, currAns = 0, arr[sz];

int get_answer()
{
    return currAns;
}

void add(int idx)
{
    currAns += arr[idx];
}

void remove(int idx)
{
    currAns -= arr[idx];
}

struct Query
{
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> &queries)
{
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries)
    {
        while (cur_l > q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l)
        {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r)
        {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, i, m, querySize, pos, ty, val, l, r;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> querySize;
    int l, r, i = 0;
    vector<Query> q(querySize, {0, 0, 0});

    // input all the queries
    while (i < querySize)
    {
        // 1 indexed
        cin >> l >> r;
        l--;
        r--;

        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;

        i++;
    }

    vector res = mo_s_algorithm(q);

    return 0;
}
