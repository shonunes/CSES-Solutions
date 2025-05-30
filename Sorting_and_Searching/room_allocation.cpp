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
    vector<pair<int, int>> startTimes(n);
    vector<pair<int, int>> endTimes(n);
    forn(i, n)
    {
        cin >> startTimes[i].first >> endTimes[i].first;
        startTimes[i].second = endTimes[i].second = i;
    }
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int count = 0;
    vector<int> ans(n);
    list<int> freeRooms;

    int endIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int start = startTimes[i].first;
        while (endTimes[endIndex].first < start)
        {
            freeRooms.push_back(ans[endTimes[endIndex].second]);
            endIndex++;
        }

        if (freeRooms.empty())
        {
            count++;
            ans[startTimes[i].second] = count;
        }
        else
        {
            ans[startTimes[i].second] = freeRooms.front();
            freeRooms.pop_front();
        }
    }

    cout << count << endl;
    for (int room : ans)
        cout << room << " ";
    cout << endl;

    return 0;
}
