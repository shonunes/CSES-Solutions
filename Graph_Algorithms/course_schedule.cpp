#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int courses, reqs;
    cin >> courses >> reqs;

    vector<vector<int>> adj(courses);
    vector<int> parents(courses, 0);
    for (int i = 0; i < reqs; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        parents[b - 1]++;
    }

    queue<int> q;
    for (int i = 0; i < courses; i++)
    {
        if (parents[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int course = q.front();
        q.pop();
        ans.push_back(course + 1);

        for (int child : adj[course])
        {
            parents[child]--;
            if (parents[child] == 0)
                q.push(child);
        }
    }

    if ((int) ans.size() == courses)
    {
        for (int course : ans)
        {
            cout << course << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
