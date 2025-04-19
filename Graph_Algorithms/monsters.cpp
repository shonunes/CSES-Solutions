#include <bits/stdc++.h>
using namespace std;

#define INF 2e9

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

int n, m;

enum moves
{
    DOWN = 0,
    LEFT = 1,
    UP = 2,
    RIGHT = 3
};

bool inbounds(int x, int y)
{
    return x != -1 && y != -1 && x != n && y != m;
}

bool available(int x, int y, vector<vector<char>> &grid)
{
    return inbounds(x, y) && grid[x][y] == '.';
}

bool isBoundary(int x, int y)
{
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}

pair<int, int> bfs(queue<pair<int, int>> &q, vector<vector<int>> &dists, vector<vector<char>> &grid, vector<vector<moves>> &mov, bool targetBFS)
{
    while (!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        int dist = dists[cell.first][cell.second];

        for (int i = 0; i < 4; i++)
        {
            int x = cell.first + di[i];
            int y = cell.second + dj[i];
            if (!available(x, y, grid) || dists[x][y] - 1 <= dist)
                continue;

            dists[x][y] = dist + 1;
            if (targetBFS)
            {
                mov[x][y] = (moves)i;
                if (isBoundary(x, y))
                {
                    return {x, y};
                }
            }

            q.push({x, y});
        }
    }

    return {-1, -1};
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    queue<pair<int, int>> q;
    vector<vector<int>> dists(n, vector<int>(m, INF));
    pair<int, int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                dists[i][j] = 0;
            }
            else if (grid[i][j] == 'A')
            {
                start = {i, j};
                dists[i][j] = 0;
            }
        }
    }

    if (isBoundary(start.first, start.second))
    {
        cout << "YES\n0\n";
        return 0;
    }

    vector<vector<moves>> mov(n, vector<moves>(m));
    bfs(q, dists, grid, mov, false);

    q.push(start);
    pair<int, int> cell = bfs(q, dists, grid, mov, true);

    if (cell.first == -1)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << dists[cell.first][cell.second] << endl;
    stack<moves> stack;
    while (cell != start)
    {
        moves move = mov[cell.first][cell.second];
        stack.push(move);
        move = (moves)((move + 2) % 4);
        cell = {cell.first + di[move], cell.second + dj[move]};
    }

    while (!stack.empty())
    {
        switch (stack.top())
        {
        case LEFT:
            cout << "L";
            break;
        case RIGHT:
            cout << "R";
            break;
        case UP:
            cout << "U";
            break;
        case DOWN:
            cout << "D";
            break;
        }
        stack.pop();
    }
    cout << endl;

    return 0;
}
