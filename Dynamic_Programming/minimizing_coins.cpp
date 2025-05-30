#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vv;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<bool>> vvb;
typedef vector<pll> vpll;
typedef vector<pii> vpii;

ll MOD = 1e9 + 7;
double eps = 1e-12;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

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


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    int lowerCoin = INF;
    forn(i, n) {
        cin >> coins[i];
        if (coins[i] < lowerCoin)
            lowerCoin = coins[i];
    }

    vector<int> minCoins(x + 1, INF);
    minCoins[0] = 0;
    forn(i, x + 1 - lowerCoin) {
        forn(c, n) {
            int pos = i + coins[c];
            if (pos > x)
                continue;
            minCoins[pos] = min(minCoins[pos], minCoins[i] + 1);
        }
    }

    if (minCoins[x] == INF)
        cout << "-1\n";
    else
        cout << minCoins[x] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}