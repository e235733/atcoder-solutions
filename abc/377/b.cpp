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

    vector<string> m(8);
    rep (i, 8) {
        cin >> m[i];
    }

    vector<vector<bool>> ok(8, vector<bool>(8, true));
    rep (i, 8) {
        rep (j, 8) {
            if (m[i][j] == '#') {
                rep (k, 8) {
                    ok[i][k] = false;
                }
                rep (k, 8) {
                    ok[k][j] = false;
                }
            }
        }
    }

    int count = 0;
    rep (i, 8) {
        rep (j, 8) {
            if (ok[i][j]) {
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}