#include <bits/stdc++.h>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using pii = pair<i64,i64>;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
#define debug(x) cerr << #x << " = " << x << endl
#define INF INT64_MAX


vector<i64> dijkstra(vector<vector<pii>>& adj, int source) {
    i64 n = adj.size();
    vector<i64> dist(n, INF);
    vector<bool> visited(n, false);
    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}




int main(void)
{
    i64 n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n, vector<pii>());
    for (i64 i = 0; i < m; i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].pb(make_pair(b - 1, c));
    }

    auto dist = dijkstra(adj, 0);

    cout << 0;
    for (i64 i = 1; i < n; i++) {
        cout << ' ' << dist[i]; 
    }
    cout << endl;

    return 0;
}