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

    string t, u;
    cin >> t >> u;
    int len_t = t.size();
    int len_u = u.size();

    // 全探索する
    // u の開始位置
    rep(i, len_t-len_u+1) {
        bool is_matched = true;
        // 適合検査
        rep (j, len_u) {
            if (u[j] != t[i+j] && t[i+j] != '?') {
                is_matched = false;
                break;
            }
        }
        if (is_matched) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}