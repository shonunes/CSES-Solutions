#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF LONG_LONG_MAX

void floyd_warshall(int &cities, vector<vector<ll>> &dist)
{
    for (int k = 0; k < cities; k++)
    {
        for (int i = 0; i < cities; i++)
        {
            for (int j = 0; j < cities; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(void)
{
    int cities, roads, queries;
    cin >> cities >> roads >> queries;

    vector<vector<ll>> dist(cities, vector<ll>(cities, INF));
    for (int i = 0; i < roads; i++)
    {
        ll a, b, length;
        cin >> a >> b >> length;
        a--;
        b--;
        dist[a][b] = min(dist[a][b], length);
        dist[b][a] = min(dist[b][a], length);
    }
    for (int i = 0; i < cities; i++)
    {
        dist[i][i] = 0;
    }

    floyd_warshall(cities, dist);

    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            if (dist[i][j] == INF)
                dist[i][j] = -1;
        }
    }

    for (int i = 0; i < queries; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << dist[start - 1][end - 1] << endl;
    }

    return 0;
}
