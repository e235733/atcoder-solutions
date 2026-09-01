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

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> S(h);
    rep (i, h) cin >> S[i];

    vector<bool> sr(h, true), sc(w, true);
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') {
                sr[i] = false;
                sc[j] = false;
            }
        }
    }
    debug(sr, sc);

    int ans = 0;

    vector<int> safe;
    vector<bool> used(h*w, false);
    rep (i, h) {
        rep (j, w) {
            if (sr[i] && sc[j]) {
                ++ans;
                safe.push_back(i*w+j);
                used[i*w+j] = true;
            }
        }
    }

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};

    rep (i, k) {
        vector<int> next_safe;
        for (int p : safe) {
            int cr = p / w;
            int cc = p % w;

            rep (j, 4) {
                int nr = cr + dr[j];
                int nc = cc + dc[j];
                if (nr == -1 || nr == h || nc == -1 || nc == w) continue;

                int v = nr * w + nc;
                if (S[nr][nc] == '#' || used[v]) continue;

                ++ans;
                used[v] = true;
                next_safe.push_back(v);
            }
        }
        safe = next_safe;
    }

    cout << ans << '\n';

    return 0;
}