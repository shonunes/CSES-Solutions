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
typedef vector<vector<int>> vvi;
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

void solve(vi &input, int &k, int &n)
{
    int n1 = n / 2, n2 = n - n1;
    vi v1(n1), v2(n2);
    forn(i, n)
    {
        if (i < n1)
            v1[i] = input[i];
        else
            v2[i - n1] = input[i];
    }

    unordered_map<int, ll> firstSums;
    firstSums.reserve(1<<n1);
    forn(i, 1 << n1) {
        ll sum = 0;
        forn(j, n1) {
            if (i & (1 << j))
                sum += v1[j];
            
            if (sum > k)
                break;
        }

        if (sum <= k)
            firstSums[sum]++;
    }

    ll ans = 0;
    forn(i, 1 << n2) {
        ll sum = 0;
        forn(j, n2) {
            if (i & (1 << j))
                sum += v2[j];
            
            if (sum > k)
                break;
        }
        if (sum <= k)
            ans += firstSums[k - sum];
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi v(n);
    forn(i, n)
    {
        cin >> v[i];
    }

    solve(v, k, n);
    

    return 0;
}
