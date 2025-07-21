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
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline ll mod(ll a, ll m) { return ((a % m) + m) % m; }

// Nodes start at index 1, index 0 is ignored
vll seg_tree;

ll __query_tree(ll node, ll node_start, ll node_end, ll query)
{
    if (node_start > query || node_end < query)
        return 0;

    if (node_start == node_end)
        return seg_tree[node];

    ll mid = (node_start + node_end) / 2;
    return mod(seg_tree[node] +
                   __query_tree(2 * node, node_start, mid, query) +
                   __query_tree(2 * node + 1, mid + 1, node_end, query),
               MOD);
}

void __update_tree(ll node, ll node_start, ll node_end, ll range_start, ll range_end, ll val)
{
    if (node_start >= range_start && node_end <= range_end)
    {
        seg_tree[node] += val;
        return;
    }

    if (node_start > range_end || node_end < range_start)
        return;

    ll mid = (node_start + node_end) / 2;
    __update_tree(2 * node, node_start, mid, range_start, range_end, val);
    __update_tree(2 * node + 1, mid + 1, node_end, range_start, range_end, val);
}

void build_tree(ll n)
{
    // Find next power of 2
    ll m = n - 1;
    m |= m >> 1;
    m |= m >> 2;
    m |= m >> 4;
    m |= m >> 8;
    m |= m >> 16;
    m |= m >> 32;
    m++;

    seg_tree.resize(2 * m);
}

ll query_tree(ll query)
{
    ll res = mod(1 + __query_tree(1, 1, seg_tree.size() / 2, query), MOD);
    __update_tree(1, 1, seg_tree.size() / 2, query + 1, seg_tree.size(), res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vll arr(n);
    set<ll> vals;
    vpll order;
    forn(i, n)
    {
        cin >> arr[i];
        vals.insert(arr[i]);
    }

    int count = 0;
    map<ll, ll> mp;
    for (ll val : vals)
        mp[val] = ++count;

    build_tree(count);

    ll ans = 0;
    forn(i, n)
    {
        ll val = query_tree(mp[arr[i]]);
        ans = mod(ans + val, MOD);
    }
    cout << ans << endl;

    return 0;
}
