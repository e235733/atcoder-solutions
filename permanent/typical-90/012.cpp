#include <bits/stdc++.h>
#include <atcoder/dsu>
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

    int h, w, q;
    cin >> h >> w >> q;

    // union-find
    dsu d(h*w);
    vector<bool> is_red(h*w, false);

    rep (_, q) {
        int type;
        cin >> type;

        if (type == 1) {
            int r, c;
            cin >> r >> c;
            int idx = (r - 1) * w + c - 1;
            debug(r, c, idx);
            is_red[idx] = true;

            // 周囲が赤ならグループ化
            if (r > 1) {
                if (is_red[idx - w]) {
                    d.merge(idx, idx - w);
                }
            }
            if (r < h) {
                if (is_red[idx + w]) {
                    d.merge(idx, idx + w);
                }
            }
            if (c > 1) {
                if (is_red[idx - 1]) {
                    d.merge(idx, idx - 1);
                }
            }
            if (c < w) {
                if (is_red[idx + 1]) {
                    d.merge(idx, idx + 1);
                }
            }
        }
        else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            int idx_a = (ra - 1) * w + ca - 1;
            int idx_b = (rb - 1) * w + cb - 1;
            debug(ra, ca, idx_a);
            debug(rb, cb, idx_b);

            if (is_red[idx_a] && is_red[idx_b] && d.same(idx_a, idx_b)) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
        }
        debug(is_red);
        debug(d.groups());
    }

    return 0;
}