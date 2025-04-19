#include <bits/stdc++.h>
using namespace std;

int bfs(int target, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[0] = 0;
    queue<pair<int, int>> q;
    for (int neighbor : adj[0])
    {
        q.push({neighbor, 2});
        visited[neighbor] = 0;

        if (neighbor == target)
            return 2;
    }

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        int computer = top.first;

        for (int neighbor : adj[computer])
        {
            if (visited[neighbor] != -1)
                continue;

            visited[neighbor] = computer;
            if (neighbor == target)
                return top.second + 1;

            q.push({neighbor, top.second + 1});
        }
    }

    return -1;
}

int main(void)
{
    int computers, connections;
    cin >> computers >> connections;

    vector<int> visited(computers, -1);
    vector<vector<int>> adj(computers);

    for (int i = 0; i < connections; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = bfs(computers - 1, adj, visited);

    if (ans == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << ans << endl;
        int cur = computers - 1;
        stack<int> order;
        while (cur != 0)
        {
            order.push(cur + 1);
            cur = visited[cur];
        }

        cout << 1;
        while (!order.empty())
        {
            cout << ' ' << order.top();
            order.pop();
        }
        cout << endl;
    }

    return 0;
}
