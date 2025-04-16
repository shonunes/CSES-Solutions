#include <bits/stdc++.h>
using namespace std;

int dfs(int pupil, vector<int> &team, vector<vector<int>> &adj)
{
    for (int neighbor : adj[pupil])
    {
        if (team[neighbor] == 0)
        {
            team[neighbor] = team[pupil] ^ 3;
            if (dfs(neighbor, team, adj) == 1)
                return 1;
        }
        else if (team[neighbor] == team[pupil])
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int pupils, friendships;
    cin >> pupils >> friendships;

    vector<int> team(pupils, 0);
    vector<vector<int>> adj(pupils);

    for (int i = 0; i < friendships; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool invalid = false;
    for (int i = 0; i < pupils && !invalid; i++)
    {
        if (team[i] == 0)
        {
            team[i] = 1;
            invalid = dfs(i, team, adj) == 1;
        }
    }
    if (invalid)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = 0; i < pupils; i++)
    {
        cout << team[i] << ' ';
    }
    cout << endl;

    return 0;
}
