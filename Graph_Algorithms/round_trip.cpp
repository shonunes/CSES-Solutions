#include <bits/stdc++.h>
using namespace std;

int dfs(int cur, int parent, vector<int> &parents, vector<vector<int>> &adj)
{
    parents[cur] = parent;
    for (int city : adj[cur])
    {
        if (city == parent)
            continue;
        
        if (parents[city] != -1)
        {
            parents[city] = cur;
            return city;
        }
        int res = dfs(city, cur, parents, adj);
        if (res != -1)
            return res;
    }

    return -1;
}

void printAnswer(int start, vector<int> &parents)
{
    vector<int> ans = {start + 1};

    int city = parents[start];
    while (city != start)
    {
        ans.push_back(city + 1);
        city = parents[city];
    }
    ans.push_back(start + 1);

    cout << ans.size() << endl;
    for (int location : ans)
    {
        cout << location << ' ';
    }
    cout << endl;
}

int main(void)
{
    int cities, roads;
    cin >> cities >> roads;

    vector<int> parents(cities, -1);
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
        if (parents[i] == -1)
        {
            int res = dfs(i, i, parents, adj);
            if (res != -1)
            {
                printAnswer(res, parents);
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
