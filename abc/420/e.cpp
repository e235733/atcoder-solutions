#include <bits/stdc++.h>
#include <atcoder/dsu.hpp>
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

    int n, q;
    cin >> n >> q;

    // union find
    dsu d(n+1);
    // 各点が黒であるか
    vector<bool> is_black(n+1, false);
    // 連結成分の黒の数を leader に記録
    vector<int> num_black(n+1, 0);

    rep (_, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u = d.leader(u);
            v = d.leader(v);
            if (u != v) {
                int w = d.merge(u, v);
                if (w == u) {
                    num_black[u] += num_black[v];
                    num_black[v] = 0;
                }
                else {
                    num_black[v] += num_black[u];
                    num_black[u] = 0;
                }
            }
        }
        else if (type == 2) {
            int v;
            cin >> v;

            int w = d.leader(v);
            if (is_black[v]) {
                num_black[w]--;
            }
            else {
                num_black[w]++;
            }
            is_black[v] = !is_black[v];
        }
        else {
            int v;
            cin >> v;

            int w = d.leader(v);
            if (num_black[w]) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
        }
    }

    return 0;
}