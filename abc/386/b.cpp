#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    string s;
    cin >> s;

    int result = 0;
    int count_zero = 0;
    for (char c : s) {
        if (c == '0') {
            count_zero++;
        }
        else {
            result += count_zero % 2 + count_zero / 2;
            count_zero = 0;
            result++;
        }
    }
    result += count_zero % 2 + count_zero / 2;

    cout << result << '\n';

    return 0;
}