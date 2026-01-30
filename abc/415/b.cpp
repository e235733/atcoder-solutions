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
    debug(s);
    // 1 番目の品物か
    bool is_first = true;
    // 小さい順に見ていく
    rep (i, s.size()) {
        // 品物に対する処理
        if (s[i] == '#') {
            if (is_first) {
                cout << i+1 << ',';
                is_first = false;
            }
            else {
                cout << i+1 << endl;
                is_first = true;
            }
        }
    }

    return 0;
}