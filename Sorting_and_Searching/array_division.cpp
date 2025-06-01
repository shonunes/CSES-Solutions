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

bool check(ll maxSum, int k, int n, vi &arr)
{
    ll arrays = 1;
    ll currentSum = 0;
    forn(i, n)
    {
        if (currentSum + arr[i] > maxSum)
        {
            if (arrays == k)
                return false;
            arrays++;
            currentSum = arr[i];
        }
        else
        {
            currentSum += arr[i];
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi arr(n);
    int maxNum = 0;
    forn(i, n)
    {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }

    ll start = maxNum, end = 2e14;
    while (start < end)
    {
        ll mid = start + (end - start) / 2;

        if (!check(mid, k, n, arr))
            start = mid + 1;
        else
            end = mid;
    }
    cout << end << endl;

    return 0;
}
