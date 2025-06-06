#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    set<int> numbers;
    for (int i = 1; i <= n; i++)
    {
        numbers.emplace_hint(numbers.end(), i);
    }

    int last = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = numbers.upper_bound(last);
        if (it == numbers.end())
            it = numbers.begin();

        it = next(it);
        if (it == numbers.end())
            it = numbers.begin();

        int val = *it;
        cout << val << ' ';
        last = val;
        numbers.erase(it);
    }
    cout << endl;

    return 0;
}