#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    multiset<int> towerTops;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cube;
        cin >> cube;

        auto it = towerTops.upper_bound(cube);

        if (it == towerTops.end())
        {
            towerTops.insert(cube);
            ans++;
        }
        else
        {
            towerTops.erase(it);
            towerTops.insert(cube);
        }
    }

    cout << ans << endl;

    return 0;
}
