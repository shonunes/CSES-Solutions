#include <bits/stdc++.h>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define sz(x) (int)(x).size()
#define debug(x) cerr << #x << " = " << x << endl

vector<vector<bool>> visited;
vector<vector<bool>> graph;
vector<pair<char, int>> path;
bool found = false;

void BFS(pair<int,int> root, pair<int,int> goal)
{
    int m = graph.size(), n = graph[0].size(), i = 0;
    pair<int,int> cur;
    queue<pair<pair<int,int>, int>> Q;
    visited[root.first][root.second] = true;
    Q.push({root, -1});

    while (!Q.empty())
    {
        int pos;
        cur = Q.front().first;
        pos = Q.front().second;
        Q.pop();


        int x = cur.first, y = cur.second;
        if (x != 0 && graph[x - 1][y] && visited[x - 1][y] == false)
        {
            visited[x - 1][y] = true;
            Q.push({{x - 1, y}, i});
            path.pb({'U', pos});
            if (make_pair(x - 1, y) == goal) {
                found = true;
                return;
            }
            i++;
        }
        if (y != 0 && graph[x][y - 1] && visited[x][y - 1] == false)
        {
            visited[x][y - 1] = true;
            Q.push({{x, y - 1}, i});
            path.pb({'L', pos});
            if (make_pair(x, y - 1) == goal) {
                found = true;
                return;
            }
            i++;
        }
        if (x != m - 1 && graph[x + 1][y] && visited[x + 1][y] == false)
        {
            visited[x + 1][y] = true;
            Q.push({{x + 1, y}, i});
            path.pb({'D', pos});
            if (make_pair(x + 1, y) == goal) {
                found = true;
                return;
            }
            i++;
        }
        if (y != n - 1 && graph[x][y + 1] && visited[x][y + 1] == false)
        {
            visited[x][y + 1] = true;
            Q.push({{x, y + 1}, i});
            path.pb({'R', pos});
            if (make_pair(x, y + 1) == goal) {
                found = true;
                return;
            }
            i++;
        }
    }
}

int main(void)
{
    int l, c;
    cin >> l >> c;
    pair<int, int> start, end;
    visited.assign(l, vector<bool>(c, false));
    graph.assign(l, vector<bool>(c, false));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                graph[i][j] = true;
            else if (c == 'A')
                start = {i, j};
            else if (c == 'B') {
                end = {i, j};
                graph[i][j] = true;
            }
        }
    }

    BFS(start, end);
    if (!found) {
        cout << "NO\n";
        return 0;
    }

    int cur = path.size() - 1;
    string ans;
    while (cur >= 0) {
        char dir = path[cur].first;
        int next = path[cur].second;
        ans += dir;
        cur = next;
    }
    reverse(ans.begin(), ans.end());

    cout << "YES\n" << ans.size() << endl << ans << endl;

    return 0;
}