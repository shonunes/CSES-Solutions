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
typedef vector<vector<int>> vv;
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
#define endln '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline int mod(int a, int m) { return ((a % m) + m) % m; }

void DFS(vvb &visited, vvb &adj, pii v, int &n, int &m)
{
    int x = v.fi, y = v.se;
    visited[x][y] = true;

    if (x != 0 && adj[x - 1][y] && visited[x - 1][y] == false)
    {
        DFS(visited, adj, {x - 1, y}, n, m);
    }
    if (y != 0 && adj[x][y - 1] && visited[x][y - 1] == false)
    {
        DFS(visited, adj, {x, y - 1}, n, m);
    }
    if (x != n - 1 && adj[x + 1][y] && visited[x + 1][y] == false)
    {
        DFS(visited, adj, {x + 1, y}, n, m);
    }
    if (y != m - 1 && adj[x][y + 1] && visited[x][y + 1] == false)
    {
        DFS(visited, adj, {x, y + 1}, n, m);
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<bool>> graph(n, vector<bool>(m, false));

    forn(i, n)
    {
        forn(j, m)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                graph[i][j] = true;
            }
        }
    }

    int ans = 0;
    forn(i, n)
    {
        forn(j, m)
        {
            if (graph[i][j] && !visited[i][j])
            {
                DFS(visited, graph, {i, j}, n, m);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
