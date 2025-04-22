#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    vector<ll> startIndices = {0, 9};
    vector<ll> startNumbers = {1, 10};
    int digits = 2;
    ll tens = 10;
    while (true)
    {
        ll nextIndex = startIndices[digits - 1] + tens * 9 * digits;
        digits++;
        tens *= 10;
        startIndices.push_back(nextIndex);
        startNumbers.push_back(tens);
        if (nextIndex > 1e18)
            break;
    }

    int q;
    cin >> q;

    while (q--)
    {
        ll query;
        cin >> query;
        query--;

        auto it = upper_bound(startIndices.begin(), startIndices.end(), query);
        int digits = distance(startIndices.begin(), it);
        it = prev(it);
        ll startIndex = *it;
        ll startNumber = startNumbers[digits - 1];

        long long number = startNumber + (query - startIndex) / digits;
        int digit = digits - (query - startIndex) % digits - 1;
        for (int i = 0; i < digit; i++)
        {
            number /= 10;
        }
        cout << number % 10 << endl;
    }

    return 0;
}