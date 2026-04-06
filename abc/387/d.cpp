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
    int s_r, s_c, g_r, g_c;
    rep (i, h) {
        cin >> S[i];
        rep (j, w) {
            if (S[i][j] == 'S') {
                s_r = i;
                s_c = j;
            }
            if (S[i][j] == 'G') {
                g_r = i;
                g_c = j;
            }
        }
    }
    debug(s_r, s_c, g_r, g_c);

    int count = 0;
    vector<pair<bool, pair<int, int>>> currents = {{true, {s_r, s_c}}, {false, {s_r, s_c}}};
    vector<vector<pair<bool, bool>>> is_visited(h, vector<pair<bool, bool>>(w, {false, false}));
    is_visited[s_r][s_c].first = true;
    is_visited[s_r][s_c].second = true;
    while (currents.size()) {
        vector<pair<bool, pair<int, int>>> nexts;
        for (auto p : currents) {
            bool is_vertical = p.first;
            auto [r, c] = p.second;

            if (S[r][c] == '#') {
                continue;
            }

            if (r == g_r && c == g_c) {
                cout << count << '\n';
                return 0;
            }

            if (is_vertical) {
                if (r > 0) {
                    if (!is_visited[r-1][c].second) {
                        nexts.push_back({false, {r-1, c}});
                        is_visited[r-1][c].second = true;
                    }
                }
                if (r < h - 1) {
                    if (!is_visited[r+1][c].second) {
                        nexts.push_back({false, {r+1, c}});
                        is_visited[r+1][c].second = true;
                    }
                }
            }
            else {
                if (c > 0) {
                    if (!is_visited[r][c-1].first) {
                        nexts.push_back({true, {r, c-1}});
                        is_visited[r][c-1].first = true;
                    }
                }
                if (c < w - 1) {
                    if (!is_visited[r][c+1].first) {
                        nexts.push_back({true, {r, c+1}});
                        is_visited[r][c+1].first = true;
                    }
                }
            }   
        }
        debug(nexts);
        currents = nexts;
        count++;
    }
    cout << -1 << '\n';

    return 0;
}