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

struct range
{
    int x, y, pos;
};

bool sortContains(range left, range right)
{
    return left.x > right.x || (left.x == right.x && left.y < right.y);
}

bool sortContained(range left, range right)
{
    return left.x < right.x || (left.x == right.x && left.y > right.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<range> ranges(n);
    forn(i, n)
    {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].pos = i;
    }
    sort(ranges.begin(), ranges.end(), sortContains);
    vi contains(n);
    int minY = ranges[0].y;
    forsn(i, 1, n)
    {
        range r = ranges[i];
        if (r.y >= minY)
            contains[r.pos] = 1;
        else
            minY = r.y;
    }
    for (int c : contains)
        cout << c << ' ';
    cout << endl;

    sort(ranges.begin(), ranges.end(), sortContained);
    vi contained(n);
    int maxY = ranges[0].y;
    forsn(i, 1, n)
    {
        range r = ranges[i];
        if (r.y <= maxY)
            contained[r.pos] = 1;
        else
            maxY = r.y;
    }
    for (int c : contained)
        cout << c << ' ';
    cout << endl;

    return 0;
}
