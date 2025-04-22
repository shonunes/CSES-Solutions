#include <bits/stdc++.h>

using namespace std;

int solve(int x, vector<bool> &column, vector<bool> &leftDiagonal, vector<bool> &rightDiagonal, vector<vector<char>> &grid)
{
    if (x == 8)
        return 1;
    
    int count = 0;
    for (int j = 0; j < 8; j++)
    {
        if (grid[x][j] == '.' && !column[j] && !leftDiagonal[x + j] && !rightDiagonal[x - j + 7])
        {
            column[j] = true;
            leftDiagonal[x + j] = true;
            rightDiagonal[x - j + 7] = true;
            count += solve(x + 1, column, leftDiagonal, rightDiagonal, grid);
            column[j] = false;
            leftDiagonal[x + j] = false;
            rightDiagonal[x - j + 7] = false;
        }
    }

    return count;
}

int main(void)
{
    vector<vector<char>> grid(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<bool> column(8, false);
    vector<bool> leftDiagonal(15, false);
    vector<bool> rightDiagonal(15, false);

    cout << solve(0, column, leftDiagonal, rightDiagonal, grid) << endl;

    return 0;
}
