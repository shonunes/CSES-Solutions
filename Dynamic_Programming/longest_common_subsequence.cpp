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

inline int mod(int a, int m)
{
    return ((a % m) + m) % m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    forn(i, n)
    {
        cin >> a[i];
    }
    forn(i, m)
    {
        cin >> b[i];
    }

    vvi mem(n + 1, vi(m + 1, 0));
    forsn(i, 1, n + 1)
    {
        forsn(j, 1, m + 1)
        {
            if (a[i - 1] == b[j - 1])
                mem[i][j] = mem[i - 1][j - 1] + 1;
            else
                mem[i][j] = max(mem[i][j], max(mem[i - 1][j], mem[i][j - 1]));
        }
    }

    int len = mem[n][m];
    vi lcs(len);
    int left = len, i = n, j = m;
    while (left != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[--left] = a[--i];
            j--;
        }
        else if (mem[i - 1][j] >= mem[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << len << endl;

    for (int num : lcs)
    {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
