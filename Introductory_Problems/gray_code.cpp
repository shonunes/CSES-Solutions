#include <bits/stdc++.h>

using namespace std;
using i32 = int32_t;
using i64 = int64_t;

int main(void)
{
    i64 n;
    cin >> n;
    for (i64 i = 0; i < (1 << n); i++) {
        i64 gray = i ^ (i >> 1);
        bitset<32> b(gray);
        string s = b.to_string();
        cout << s.substr(32-n) << '\n';
    }


    return 0;
}
