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

struct Node
{
    ll i;
    ll start;
    ll end;
    ll counts;

    Node() : i(-1), start(0), end(2e9), counts(0) {}
    Node(ll i, ll start, ll end) : i(i), start(start), end(end), counts(0) {}
    Node(ll i, ll start, ll end, ll counts) : i(i), start(start), end(end), counts(counts) {}
};

struct Operation
{
    char op;
    ll a;
    ll b;

    Operation(): op('\0'), a(0), b(0) {}
    Operation(char op, ll a, ll b) : op(op), a(a), b(b) {}
};

// Nodes start at index 1, index 0 is ignored
vector<Node> seg_tree;

ll __query_tree(Node &node, ll query_start, ll query_end)
{
    if (node.start >= query_start && node.end <= query_end)
        return seg_tree[node.i].counts;

    if (node.start > query_end || node.end < query_start)
        return 0;

    return __query_tree(seg_tree[2 * node.i], query_start, query_end) +
           __query_tree(seg_tree[2 * node.i + 1], query_start, query_end);
}

void __update_tree(Node &node, ll target, ll val)
{
    if (node.start == node.end)
    {
        seg_tree[node.i].counts += val;
        return;
    }

    Node *left = &seg_tree[2 * node.i], *right = &seg_tree[2 * node.i + 1];
    if (target <= left->end)
        __update_tree(*left, target, val);
    else
        __update_tree(*right, target, val);

    node.counts = left->counts + right->counts;
}

void build_tree(ll n, map<ll, ll> &mp)
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
    int idx = m;
    for (auto entry : mp)
    {
        seg_tree[idx] = Node(idx, entry.first, entry.first, entry.second);
        idx++;
    }

    forsn(i, idx, 2 * m)
        seg_tree[i] = Node(i, 1e9 + i, 1e9 + i, 0);

    rforsn(i, m - 1, 1)
    {
        seg_tree[i].i = i;
        seg_tree[i].start = seg_tree[2 * i].start;
        seg_tree[i].end = seg_tree[2 * i + 1].end;
        seg_tree[i].counts = seg_tree[2 * i].counts + seg_tree[2 * i + 1].counts;
    }
}

ll query_tree(ll query_start, ll query_end)
{
    return __query_tree(seg_tree[1], query_start, query_end);
}

void update_tree(ll cur, ll target)
{
    __update_tree(seg_tree[1], cur, -1);
    __update_tree(seg_tree[1], target, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vll arr(n);
    map<ll, ll> mp;
    forn(i, n)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    vector<Operation> ops(q);
    forn(i, q)
    {
        cin >> ops[i].op >> ops[i].a >> ops[i].b;
        if (ops[i].op == '!')
            mp[ops[i].b] = mp[ops[i].b];
    }
    build_tree(mp.size(), mp);

    for(Operation op : ops)
    {
        if (op.op == '!')
        {
            ll cur = arr[op.a - 1];
            arr[op.a - 1] = op.b;
            update_tree(cur, op.b);
        }
        else
            cout << query_tree(op.a, op.b) << endl;
    }

    return 0;
}
