#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<bool>> vvb;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

ll MOD = 1e9 + 7;
double eps = 1e-12;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define endl '\n'
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline int mod(int a, int m) { return ((a % m) + m) % m; }

void solve()
{
    ll x, y;
    cin >> y >> x;

    ll res;
    if (x >= y)
    {
        if (x & 1)
            res = x * x - y + 1;
        else
            res = (x - 1) * (x - 1) + y;
    }
    else
    {
        if (y & 1)
            res = (y - 1) * (y - 1) + x;
        else
            res = y * y - x + 1;
    }

    cout << res << endl;
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
