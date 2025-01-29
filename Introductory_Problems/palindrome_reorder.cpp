#include <bits/stdc++.h>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;

int main(void)
{
    string s;
    cin >> s;

    i64 odd = 0, oddIndex = -1;
    vector<i64> freq(26);

    for (char c : s) {
        freq[c - 'A']++;
    }


    for (i64 i = 0; i < 26; i++) {
        if (freq[i] % 2) {
            odd++;
            if (odd != 1) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            oddIndex = i;
        }
    }

    string ans;
    for (i64 i = 0; i < 26; i++) {
        if (freq[i] % 2 == 0) {
            i64 lim = freq[i] / 2;
            for (i64 j = 0; j < lim; j++)
                ans.push_back(i + 'A');
            freq[i] = lim;
        }
    }
    if (odd)
    {
        while (freq[oddIndex]--) {
            ans.push_back(oddIndex + 'A');
        }
    }
    
    for (i64 i = 25; i >= 0; i--) {
        while (freq[i] > 0) {
            ans.push_back(i + 'A');
            freq[i]--;
        }
    }
    cout << ans << '\n';

    return 0;
}
