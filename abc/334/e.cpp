#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    rep (i, h) cin >> S[i];

    dsu uf(h*w);
    rep (r, h) {
        rep (c, w) {
            if (S[r][c] == '.') continue;

            rep (i, 4) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr == -1 || nr == h || nc == -1 || nc == w) continue;
                
                if (S[nr][nc] == '#') {
                    uf.merge(r*w+c, nr*w+nc);
                }
            }
        }
    }

    set<int> L;
    rep (r, h) {
        rep (c, w) {
            if (S[r][c] == '.') continue;

            L.insert(uf.leader(r*w+c));
        }
    }
    debug(L);

    mint ans = 0;
    int d = 0;
    rep (r, h) {
        rep (c, w) {
            if (S[r][c] == '#') continue;

            debug(r, c);
            ++d;
            set<int> M;
            rep (i, 4) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr == -1 || nr == h || nc == -1 || nc == w) continue;

                if (S[nr][nc] == '#') M.insert(uf.leader(nr*w+nc));
            }
            debug(M);

            ans += (int)L.size() + 1 - (int)M.size();
            debug(ans.val());
        }
    }
    debug(ans.val());
    debug(d);

    cout << (ans / d).val() << '\n';

    return 0;
}