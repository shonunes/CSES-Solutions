#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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

// See: Order-Statistic Tree
using oset = tree<int,       // key type
                  null_type, // value type
                  less<int>, // compare function
                  rb_tree_tag,
                  tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi nums(n);
    vi pos(n);
    forn(i, n)
    {
        cin >> nums[i];
        nums[i]--;
        pos[nums[i]] = i;
    }

    int rounds = 1;
    forsn(i, 1, n)
    {
        if (pos[i] < pos[i - 1])
            rounds++;
    }

    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int x = nums[a],  y = nums[b];

        if (x != 0 && a < pos[x - 1] && b >= pos[x - 1])
        {
            rounds--;
        }
        else if (x != 0 && a > pos[x - 1] && b <= pos[x - 1])
        {
            rounds++;
        }

        if (y != 0 && b < pos[y - 1] && a >= pos[y - 1])
        {
            rounds--;
        }
        else if (y != 0 && b > pos[y - 1] && a <= pos[y - 1])
        {
            rounds++;
        }

        if (x != n - 1 && a >= pos[x + 1] && b < pos[x + 1])
        {
            rounds--;
        }
        else if (x != n - 1 && a <= pos[x + 1] && b > pos[x + 1])
        {
            rounds++;
        }

        if (y != n - 1 && b >= pos[y + 1] && a < pos[y + 1])
        {
            rounds--;
        }
        else if (y != n - 1 && b <= pos[y + 1] && a > pos[y + 1])
        {
            rounds++;
        }

        cout << rounds << endl;
        swap(nums[a], nums[b]);
        pos[x] = b;
        pos[y] = a;
    }

    return 0;
}
