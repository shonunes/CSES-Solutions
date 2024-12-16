#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<char> vc;
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

inline int mod(int a, int m) { return ((a % m) + m) % m; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi arr(n);
    forn(i, n)
        cin >> arr[i];

    vvi mem(n, vi(m, 0));

    if (arr[0])
        mem[0][arr[0] - 1] = 1;
    else
    {
        forn(i, m)
            mem[0][i] = 1;
    }

    forsn(i, 1, n)
    {
        int val = arr[i] - 1;
        if (val != -1)
        {
            mem[i][val] = mem[i - 1][val];
            if (val != 0)
                mem[i][val] = mod(mem[i][val] + mem[i - 1][val - 1], MOD);
            if (val != m - 1)
                mem[i][val] = mod(mem[i][val] + mem[i - 1][val + 1], MOD);
            continue;
        }

        forn(j, m)
        {
            if (mem[i - 1][j])
            {
                mem[i][j] = mod(mem[i][j] + mem[i - 1][j], MOD);
                if (j != 0)
                    mem[i][j - 1] = mod(mem[i][j - 1] + mem[i - 1][j], MOD);
                if (j != m - 1)
                    mem[i][j + 1] = mod(mem[i][j + 1] + mem[i - 1][j], MOD);
            }
        }
    }

    int ans = 0;
    forn(j, m)
    {
        if (mem[n - 1][j])
            ans = mod(ans + mem[n - 1][j], MOD);
    }

    cout << ans << endl;

    return 0;
}
