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
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>

inline int mod(int a, int m) { return ((a % m) + m) % m; }

void hanoi(int source, int dest, int aux, int disks, vpii &moves)
{
    /**
     * The function moves a disk from source and calls itself
     * to move the last pile created (smaller than that disk) on top of the disk.
     * After doing this to every disk, we will get the final result.
     * 
     * The disks are either moved to aux or dest, depending on the amount of disks in the pile.
     * source is the stack number where our pile is.
     * dest is the stack number where we want our pile to end up.
     * aux is the stack number which is neither source or dest.
     */
    forn(i, disks)
    {
        int towerHeight = disks - i;
        if (towerHeight & 1)
        {
            moves.push_back({source, dest});
            hanoi(aux, dest, source, i, moves);
        }
        else
        {
            moves.push_back({source, aux});
            hanoi(dest, aux, source, i, moves);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vpii moves;

    hanoi(1, 3, 2, n, moves);

    cout << moves.size() << endl;
    for (pii move : moves)
        cout << move.first << ' ' << move.second << endl;

    return 0;
}
