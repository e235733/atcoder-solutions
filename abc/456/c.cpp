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

    int length = s.size();
    int l = 0;
    int r = 0;
    char prev = ' ';
    ll result = 0;
    while (r != length) {
        if (s[r] != prev) {
            prev = s[r];
            r++;
        }
        else {
            result += 1LL * (r - l) * (r - l + 1) / 2;
            prev = ' ';
            l = r;
        }
    }
    result += 1LL * (r - l) * (r - l + 1) / 2;

    cout << result % 998244353 << '\n';

    return 0;
}