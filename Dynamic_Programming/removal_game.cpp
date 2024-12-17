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

    int n;
    cin >> n;
    vll num_list(n);
    forn(i, n)
        cin >> num_list[i];

    // The memory contains the score that you can get in any range of the list
    vvll mem(n + 1);
    forn(i, n) {
        mem[i] = vll(n - i + 1);
        mem[i][n - i - 1] = num_list[i];
    }
    mem[n] = {0};

    rforn(i, n - 2)
    {
        rforn(j, n - i - 2)
        {
            if (mem[i + 1][j] >= mem[i][j + 1])
                mem[i][j] = num_list[n - j - 1] + min(mem[i + 1][j + 1], mem[i][j + 2]);
            else
                mem[i][j] = num_list[i] + min(mem[i + 1][j + 1], mem[i + 2][j]);
        }
    }

    cout << mem[0][0] << endl;

    return 0;
}
