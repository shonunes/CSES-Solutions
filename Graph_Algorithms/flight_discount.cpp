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

struct City
{
    int pos;
    ll dist;
    bool discounted;

    City(int pos) : pos(pos), dist(0), discounted(false) {};
    City(int pos, ll dist) : pos(pos), dist(dist), discounted(false) {};
    City(int pos, ll dist, bool discounted) : pos(pos), dist(dist), discounted(discounted) {};

    bool operator<(City other) const
    {
        return this->dist < other.dist || (this->dist == other.dist && this->discounted < other.discounted);
    }

    bool operator>(City other) const
    {
        return this->dist > other.dist || (this->dist == other.dist && this->discounted > other.discounted);
    }
};

void dijkstra(int source, int dest, vvpii &adj, vvll &dist)
{
    ll n = adj.size();
    vvb visited(n, vb(2, false));
    dist[source][0] = 0;
    priority_queue<City, vector<City>, greater<City>> pq;
    pq.push(City(source));
    while (!pq.empty())
    {
        City city = pq.top();
        int u = city.pos;
        bool discounted = city.discounted;
        pq.pop();
        if (u == dest && discounted == true)
            break;
        if (visited[u][discounted])
            continue;
        visited[u][discounted] = true;
        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[v][discounted] > dist[u][discounted] + weight)
            {
                dist[v][discounted] = dist[u][discounted] + weight;
                pq.push(City(v, dist[v][discounted], discounted));
            }
            if (!discounted && dist[v][true] > dist[u][false] + (weight >> 1))
            {
                dist[v][true] = dist[u][false] + (weight >> 1);
                pq.push(City(v, dist[v][true], true));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;
    vvpii adj(v);
    forn(i, e)
    {
        int src, dest, w;
        cin >> src >> dest >> w;
        adj[src - 1].push_back({dest - 1, w});
    }

    vvll dist(v, vll(2, INF));
    dijkstra(0, v - 1, adj, dist);

    cout << dist[v - 1][true] << endl;

    return 0;
}
