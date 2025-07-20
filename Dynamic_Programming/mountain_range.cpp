#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<bool>> vvb;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

ll MOD = 1e9 + 7;
double eps = 1e-12;

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
vpll seg_tree;

void build_tree(ll &n, vll &arr)
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
        seg_tree[m + i] = {arr[i], i + 1};
    rforsn(i, m - 1, 1)
    {
        seg_tree[i] = max(seg_tree[2 * i], seg_tree[2 * i + 1]);
        seg_tree[i] = {seg_tree[i].first, seg_tree[i].second};
    }
}

pll __query_tree(ll node, ll node_start, ll node_end, ll query_start, ll query_end)
{
    if (node_start >= query_start && node_end <= query_end)
        return seg_tree[node];

    if (node_start > query_end || node_end < query_start)
        return {0, 0};

    ll mid = (node_start + node_end) / 2;
    return max(
        __query_tree(2 * node, node_start, mid, query_start, query_end),
        __query_tree(2 * node + 1, mid + 1, node_end, query_start, query_end));
}

pll query_tree(ll query_start, ll query_end)
{
    return __query_tree(1, 1, seg_tree.size() / 2, query_start, query_end);
}

int solve(int start, int end, int max_value)
{
    pll q = query_tree(start, end);
    if (start > end || (start == end && q.first == max_value))
        return 0;
    if (start == end)
        return 1;

    if (q.first == max_value)
        return max(solve(start, q.second - 1, q.first), solve(q.second + 1, end, q.first));
    return 1 + max(solve(start, q.second - 1, q.first), solve(q.second + 1, end, q.first));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vll heights(n);
    forn(i, n)
    {
        cin >> heights[i];
    }

    build_tree(n, heights);

    cout << solve(1, n, INF) << endl;

    return 0;
}
