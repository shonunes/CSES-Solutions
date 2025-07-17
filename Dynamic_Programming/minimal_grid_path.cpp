#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<bool>> vvb;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

ll MOD = 1e9 + 7;
double eps = 1e-12;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline ll mod(ll a, ll m) { return ((a % m) + m) % m; }

vvi moves = {{0, 1}, {1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vvi grid(n, vi(n));
    forn(i, n)
    {
        forn(j, n)
        {
            char c;
            cin >> c;
            grid[i][j] = c - 'A';
        }
    }

    vi ans(2 * n - 1, 25);
    ans[0] = grid[0][0];

    vvb mem(n, vb(n, false));
    mem[0][0] = true;
    forsn(i, 1, n)
    {
        if (mem[i - 1][0] && grid[i - 1][0] == ans[i - 1])
        {
            mem[i][0] = true;
            ans[i] = grid[i][0];
        }
        if (mem[0][i - 1] && grid[0][i - 1] == ans[i - 1])
        {
            mem[0][i] = true;
            ans[i] = min(ans[i], grid[0][i]);
        }
        forsn(x, 1, i)
        {
            int y = i - x;
            if ((mem[x - 1][y] && ans[i - 1] == grid[x - 1][y]) ||
                (mem[x][y - 1] && ans[i - 1] == grid[x][y - 1]))
            {
                mem[x][y] = true;
                ans[i] = min(ans[i], grid[x][y]);
            }
        }
    }

    forsn(i, n, 2 * n - 1)
    {
        int j = i - n + 1;
        if (mem[j - 1][n - 1] && grid[j - 1][n - 1] == ans[i])
        {
            mem[j - 1][n - 1] = true;
            ans[i] = grid[j - 1][n - 1];
        }
        if (mem[n - 1][j - 1] && grid[n - 1][j - 1] == ans[i])
        {
            mem[n - 1][j - 1] = true;
            ans[i] = min(ans[i], grid[n - 1][j - 1]);
        }
        forsn(l, 1, 2 * n - i)
        {
            int x = i - n + l;
            int y = i - x;
            if ((mem[x - 1][y] && ans[i - 1] == grid[x - 1][y]) ||
                (mem[x][y - 1] && ans[i - 1] == grid[x][y - 1]))
            {
                mem[x][y] = true;
                ans[i] = min(ans[i], grid[x][y]);
            }
        }
    }

    forn(i, 2 * n - 1)
    {
        cout << (char) (ans[i] + 'A');
    }
    cout << endl;

    return 0;
}
