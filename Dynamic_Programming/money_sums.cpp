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
    vi coins(n);
    forn(i, n)
        cin >> coins[i];

    vb mem(100001, false);
    mem[0] = 1;

    vi moneySums = {0};
    int numSums = 0;
    for (int coin : coins)
    {
        int currentSums = moneySums.size();
        for (int i = 0; i < currentSums; i++)
        {
            if (!mem[moneySums[i] + coin])
            {
                mem[moneySums[i] + coin] = true;
                moneySums.pb(moneySums[i] + coin);
                numSums++;
            }
        }
    }

    sort(moneySums.begin(), moneySums.end());
    cout << numSums << endl;
    forsn(i, 1, numSums)
        cout << moneySums[i] << ' ';
    cout << moneySums[numSums] << endl;

    return 0;
}
