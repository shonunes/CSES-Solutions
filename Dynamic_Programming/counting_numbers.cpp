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

ll rec(int pos, vi &num, bool started, bool limit)
{
    if (pos == -1)
        return 1;

    if (!limit && !started)
        return 9 * rec(pos - 1, num, true, limit) + rec(pos - 1, num, false, limit);
    if (!limit)
        return 9 * rec(pos - 1, num, true, limit);

    if (started)
    {
        int digits;
        if (num[pos] > num[pos + 1])
            digits = num[pos];
        else
            digits = num[pos] + 1;

        ll not_limited = 0;
        if (digits > 1)
            not_limited = (digits - 1) * rec(pos - 1, num, started, false);

        if (num[pos] != num[pos + 1])
            return rec(pos - 1, num, started, true) + not_limited;
        else
            return not_limited;
    }
    
    return rec(pos - 1, num, false, false) +
           rec(pos - 1, num, true, true) +
           (num[pos] - 1) * rec(pos - 1, num, true, false);
}

ll solve(ll num)
{
    if (num == 0)
        return 1;

    vi v;
    while (num != 0)
    {
        v.push_back(num % 10);
        num /= 10;
    }

    int n = v.size();

    return rec(n - 1, v, false, true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a - 1) << endl;

    return 0;
}
