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

ll __query_tree(ll node, ll node_start, ll node_end, ll query_start, ll query_end)
{
    if (node_start >= query_start && node_end <= query_end)
        return seg_tree[node];

    if (node_start > query_end || node_end < query_start)
        return 0;

    ll mid = (node_start + node_end) / 2;
    return __query_tree(2 * node, node_start, mid, query_start, query_end) +
           __query_tree(2 * node + 1, mid + 1, node_end, query_start, query_end);
}

void __update_tree(ll node, ll node_start, ll node_end, ll target, ll val)
{
    if (node_start == node_end)
    {
        seg_tree[node] = val;
        return;
    }

    ll mid = (node_start + node_end) / 2;
    if (target <= mid)
        __update_tree(2 * node, node_start, mid, target, val);
    else
        __update_tree(2 * node + 1, mid + 1, node_end, target, val);

    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
}

void build_tree(ll &n, vll &arr, map<ll, deque<ll>> &mp)
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
    forn(i, n)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            seg_tree[m + i] = 1;
            mp[arr[i]] = {i + 1};
        }
        else
        {
            seg_tree[m + i] = 0;
            mp[arr[i]].push_back(i + 1);
        }
    }
    rforsn(i, m - 1, 1)
        seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1];
}

ll query_tree(ll query_start, ll query_end)
{
    return __query_tree(1, 1, seg_tree.size() / 2, query_start, query_end);
}

void update_tree(ll target, ll val)
{
    __update_tree(1, 1, seg_tree.size() / 2, target, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vll arr(n);
    forn(i, n)
    {
        cin >> arr[i];
    }
    map<ll, deque<ll>> mp;
    build_tree(n, arr, mp);

    int k = 0;
    vector<pair<pll, int>> queries(q);
    forn(i, q)
    {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    sort(all(queries));

    vector<pll> ans(q);
    forn(i, q)
    {
        while (k < queries[i].first.first - 1)
        {
            deque<ll> *dq = &mp[arr[k]];
            (*dq).pop_front();
            if (!(*dq).empty())
                update_tree((*dq)[0], 1);
            k++;
        }
        ans[i] = {
            queries[i].second,
            query_tree(queries[i].first.first, queries[i].first.second)};
    }
    sort(all(ans));
    forn(i, q)
        cout << ans[i].second << endl;

    return 0;
}
