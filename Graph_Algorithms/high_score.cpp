#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
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
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline ll mod(ll a, ll m) { return ((a % m) + m) % m; }

ll bellman_ford(int source, int n, vvpll &adj, vll &dist)
{
    vb reachable(n, false), can_reach(n, false);
    reachable[source] = true;
    can_reach[n - 1] = true;
    dist[source] = 0;
    forn(k, n - 1)
    {
        forn(u, n)
        {
            for (pll p : adj[u])
            {
                if (dist[p.first] < dist[u] + p.second)
                    dist[p.first] = dist[u] + p.second;
                if (can_reach[p.first])
                    can_reach[u] = true;
                if (reachable[u])
                    reachable[p.first] = true;
            }
        }
    }

    forn(u, n)
    {
        if (!can_reach[u] || !reachable[u])
            continue;
        for (pll p : adj[u])
        {
            if (dist[p.first] < dist[u] + p.second)
                return -1;
        }
    }
    
    return dist[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    vvpll adj(v);
    forn(i, e)
    {
        int source, dest, weight;
        cin >> source >> dest >> weight;
        adj[source - 1].push_back({dest - 1, weight});
    }

    vll dist(v, -INF);
    cout << bellman_ford(0, v, adj, dist) << endl;

    return 0;
}
