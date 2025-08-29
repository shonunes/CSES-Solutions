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

void dijkstra(int source, vector<vector<pll>> &adj, vector<ll> &ans)
{
    ll n = adj.size();
    vector<bool> visited(n, false);
    vll dist(n, INF);
    vll route_count(n, 0);
    vll min_flights(n, INF);
    vll max_flights(n, 0);
    dist[source] = 0;
    route_count[source] = 1;
    min_flights[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;
        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                route_count[v] = route_count[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
            }
            else if (dist[v] == dist[u] + weight)
            {
                route_count[v] = mod(route_count[v] + route_count[u], MOD);
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);
            }
        }
    }

    ans = {dist[n - 1], route_count[n - 1], min_flights[n - 1], max_flights[n - 1]};
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<pll>> adj(n, vector<pll>());
    vector<vector<pll>> radj(n, vector<pll>());
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].pb(make_pair(b - 1, c));
        radj[b - 1].pb(make_pair(a - 1, c));
    }

    vll ans(4);
    dijkstra(0, adj, ans);
    forn(i, 4)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}