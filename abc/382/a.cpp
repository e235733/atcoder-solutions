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

    int n, d;
    string s;
    cin >> n >> d >> s;

    int num_cookies = 0;
    rep (i, n) {
        if (s[i] == '@') {
            num_cookies++;
        }
    }

    cout << n - num_cookies + d << '\n';

    return 0;
}