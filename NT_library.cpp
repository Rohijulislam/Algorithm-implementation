#include <bits/stdc++.h>
using namespace std;
#define sz 200003
typedef long long int ll;
#define pi pair<int, int>
ll fct[sz], invfact[sz], mod = 1000000007;

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// big mode

ll power(ll x, ll i, ll mod)
{
    ll ans = 1;
    while (i > 0)
    {
        if (i & 1)
            ans = (ans * x) % mod;
        i >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

ll modInverse(ll x, ll mod)
{
    return power(x, mod - 2, mod);
}

ll ncr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    else if (r == 0 || r == n)
        return 1;

    ll res = (fct[n] * modInverse(fct[r], mod)) % mod;

    res *= modInverse(fct[n - r], mod);
    res %= mod;

    return res;
}

// factorilas 1 to n
void fact(int n)
{
    fct[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fct[i] = fct[i - 1] * i;
        fct[i] %= mod;
    }
}

// inverse factorials 1 to (n-1)
void inverseFact(int n)
{
    invfact[n - 1] = modInverse(fct[n - 1], mod);
    for (int i = n - 2; i >= 0; i--)
    {
        invfact[i] = invfact[i + 1] * (i + 1);
        invfact[i] %= mod;
    }
}

// sieve

const int N = 1e5 + 9;

int spf[N];
vector<int> primes;
void sieve()
{
    for (int i = 2; i < N; i++)
    {
        if (spf[i] == 0)
            spf[i] = i, primes.push_back(i);
        int limit = primes.size();
        for (int j = 0; j < limit && i * primes[j] < N && primes[j] <= spf[i]; j++)
        {
            spf[i * primes[j]] = primes[j];
        }
    }
}

// phi function
const int N = 1e5 + 9;
int phi[N];
void totient()
{
    for (int i = 1; i < N; i++)
        phi[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}