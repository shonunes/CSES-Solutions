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

int editDistance(string s1, string s2, int n, int m)
{
    vvi mem(n + 1, vi(m + 1, 0));
    forsn(i, 1, n + 1)
        mem[i][0] = i;
    forsn(j, 1, m + 1)
        mem[0][j] = j;

    forn(i, n)
    {
        forn(j, m)
        {
            if (s1[i] != s2[j])
                mem[i + 1][j + 1] = min(mem[i][j], min(mem[i + 1][j], mem[i][j + 1])) + 1;
            else
                mem[i + 1][j + 1] = mem[i][j];
        }
    }

    return mem[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    cout << editDistance(s1, s2, s1.size(), s2.size()) << endl;

    return 0;
}
