#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long ans = 1;
    for (int i = 0; i < n && coins[i] <= ans; i++)
    {
        ans += coins[i];
    }

    cout << ans << endl;


    return 0;
}