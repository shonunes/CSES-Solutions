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

bool sortArrival(pii cur, pii next)
{
    return cur.first < next.first;
}

bool sortLeaving(pii cur, pii next)
{
    return cur.second < next.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vpii v(n);

    forn(i, n)
    {
        int arrival, leaving;
        cin >> arrival >> leaving;
        v[i] = {arrival, leaving};        
    }

    // Save the number of customers that arrived until the arrival times
    sort(v.begin(), v.end(), sortArrival);
    map<int,int> customers;
    customers[v[0].first] = 1;
    forsn(i, 1, n)
    {
        customers[v[i].first] = customers[v[i - 1].first] + 1;
    }

    // Subtract the previous times with the customers that already left
    sort(v.begin(), v.end(), sortLeaving);
    int exited = 0, vpos = 0;
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        while (v[vpos].second < it->first)
        {
            exited++;
            vpos++;
        }
        it->second -= exited;
    }

    // Find the maximum number of customers
    // This can be done in the previous step
    int ans = 0;
    for(auto time : customers)
    {
        ans = max(ans, time.second);
    }

    cout << ans << endl;

    return 0;
}
