#include <bits/stdc++.h>
using namespace std;

void dfs(int city, vector<vector<int>> &adj, vector<int> &connected, vector<int> &visited)
{
    visited[city] = true;
    connected.push_back(city);
    for (int neighbor : adj[city])
    {
        if (!visited[neighbor])
            dfs(neighbor, adj, connected, visited);
    }
}

int main(void)
{
    int cities, roads;
    cin >> cities >> roads;

    vector<int> visited(cities, false);
    vector<vector<int>> connected;
    vector<vector<int>> adj(cities);

    for (int i = 0; i < roads; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < cities; i++)
    {
        if (!visited[i])
        {
            vector<int> connectedCities;
            dfs(i, adj, connectedCities, visited);
            connected.push_back(connectedCities);
        }
    }

    int missingRoads = connected.size() - 1;
    cout << missingRoads << endl;
    for (int i = 0; i < missingRoads; i++)
    {
        cout << connected[i][0] + 1 << ' ' << connected[i + 1][0] + 1 << endl;
    }

    return 0;
}
