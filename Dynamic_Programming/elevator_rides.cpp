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

inline ll mod(ll a, ll m) { return ((a % m) + m) % m; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, limit;
    cin >> n >> limit;

    vi weights(n);
    forn(i, n)
            cin >>
        weights[i];

    vpii mem(1 << n, {n + 1, 0});
    mem[0] = {1, 0};
    forsn(mask, 1, 1 << n)
    {
        forn(i, n)
        {
            int prev_mask = mask ^ (1 << i);
            if (prev_mask > mask)
                continue;

            pii cur;
            if (mem[prev_mask].second + weights[i] <= limit)
                cur = {mem[prev_mask].first, mem[prev_mask].second + weights[i]};
            else
                cur = {mem[prev_mask].first + 1, weights[i]};

            mem[mask] = min(mem[mask], cur);
        }
    }
    cout << mem[(1 << n) - 1].first << endl;

    return 0;
}
