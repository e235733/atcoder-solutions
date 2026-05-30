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

    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    rep (i, h) {
        cin >> S[i];
    }

    vector<vector<int>> md(h, vector<int>(w, -1));
    vector<int> cr;
    vector<int> cc;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') {
                md[i][j] = 0;
                cr.push_back(i);
                cc.push_back(j);
            }
        }
    }

    vector<int> dr = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> nr1, nc1;
    rep (i, (int)cr.size()) {
        debug(cr[i], cc[i]);
        rep (j, 8) {
            int r = cr[i] + dr[j];
            int c = cc[i] + dc[j];

            if (r < 0 || r >= h || c < 0 || c >= w) {
                continue;
            }
            debug(r, c, md[r][c]);
            if (md[r][c] != -1) {
                continue;
            }

            md[r][c] = 1;
            nr1.push_back(r);
            nc1.push_back(c);
        }
    }
    rep (i, h) {
        rep (j, w) {
            if (md[i][j] == 0) {
                md[i][j] = -1;
            }
        }
    }
    cr = nr1;
    cc = nc1;
    int d = 2;
    while (cr.size()) {
        vector<int> nr, nc;
        rep (i, (int)cr.size()) {
            debug(cr[i], cc[i]);
            rep (j, 8) {
                int r = cr[i] + dr[j];
                int c = cc[i] + dc[j];

                if (r < 0 || r >= h || c < 0 || c >= w) {
                    continue;
                }
                debug(r, c, md[r][c]);
                if (md[r][c] != -1) {
                    continue;
                }

                md[r][c] = d;
                nr.push_back(r);
                nc.push_back(c);
            }
        }
        cr = nr;
        cc = nc;
        d++;
    }
    debug(md);

    rep (i, h) {
        rep (j, w) {
            if (md[i][j] % 2) {
                cout << '.';
            }
            else {
                cout << '#';
            }
        }
        cout << '\n';
    }

    return 0;
}