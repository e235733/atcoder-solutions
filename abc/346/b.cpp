#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int w, b;
    cin >> w >> b;

    string s = "wbwbwwbwbwbw";

    rep (i, 12) {
        int cw = 0;
        int cb = 0;
        int j = i;
        while (cw <= w && cb <= b) {
            if (cw == w && cb == b) {
                cout << "Yes" << '\n';
                return 0;
            }

            if (s[j] == 'w') {
                ++cw;
            }
            else if (s[j] == 'b') {
                ++cb;
            }

            ++j;
            if (j == 12) j = 0;
        }
    }

    cout << "No" << '\n';

    return 0;
}