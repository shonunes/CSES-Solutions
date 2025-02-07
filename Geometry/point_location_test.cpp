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
double EPS = 1e-12;
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

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

// ---------------------------------------| POINTS 2D |--------------------------------------- //

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator<(point other) const
    {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator==(const point &other) const
    {
        return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
    }
};

// Euclidean distance
double dist(const point &p1, const point &p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate(const point &p, double theta)
{                                   // theta in degrees
    double rad = DEG_to_RAD(theta); // convert to radians

    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

// ---------------------------------------| LINES  2D |--------------------------------------- //

struct line
{
    double a, b, c;
};

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(const point &p1, const point &p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS) // vertical line
        l = {1.0, 0.0, -p1.x};
    else
    {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // always 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// convert point and gradient/slope to line, not for vertical line
// m = tan(theta)
void pointSlopeToLine(point p, double m, line &l)
{              // m < Inf
    l.a = -m;  // always -m
    l.b = 1.0; // always 1.0
    l.c = -((l.a * p.x) + (l.b * p.y));
}

bool areParallel(line l1, line l2)
{
    // check a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2)
{
    // also check c
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point p) if two lines are intersect
bool areIntersect(line l1, line l2, point &p)
{
    if (areParallel(l1, l2))
        return false;
    // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

// ---------------------------------------| VECTOR 2D |--------------------------------------- //

struct vec
{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b)
{
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(const vec &v, double s)
{
    return vec(v.x * s, v.y * s);
}

point translate(const point &p, const vec &v)
{
    return point(p.x + v.x, p.y + v.y);
}

double cross(const vec &v1, const vec &v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

double dot(const vec &v1, const vec &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

// ------------------------------------------------------------------------------------------- //

void solve()
{
    int x, y;
    cin >> x >> y;
    point p1(x, y);
    cin >> x >> y;
    point p2(x, y);
    cin >> x >> y;
    point p3(x, y);

    vec v1to2 = toVec(p1, p2);
    vec v1to3 = toVec(p1, p3);

    // Calculate the cross product between p1-p2 vector and p1-p3 vector
    double crossProd = cross(v1to2, v1to3);

    if (crossProd > 0)
        cout << "LEFT\n";
    else if (crossProd < 0)
        cout << "RIGHT\n";
    else
        cout << "TOUCH\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
