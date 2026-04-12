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

    int h, w, d;
    cin >> h >> w >> d;

    vector<string> S(h);
    rep (i, h) {
        cin >> S[i];
    }

    vector<pair<int, int>> current;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    int count = 0;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == 'H') {
                current.push_back({i, j});
                used[i][j] = true;
                count++;
            }
        }
    }
    debug(current);

    vector<int> d_r = {-1, 1, 0, 0};
    vector<int> d_c = {0, 0, -1, 1};

    int dist = 0;
    while (dist != d && current.size()) {
        vector<pair<int, int>> next;
        for (auto p : current) {
            int r = p.first;
            int c = p.second;

            rep (i, 4) {
                int n_r = r + d_r[i];
                int n_c = c + d_c[i];

                if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) {
                    continue;
                }

                if (S[n_r][n_c] == '#' || used[n_r][n_c]) {
                    continue;
                }

                count++;
                used[n_r][n_c] = true;
                next.push_back({n_r, n_c});
            }
        }
        current = next;
        dist++;
    }

    cout << count << '\n';

    return 0;
}