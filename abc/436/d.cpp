#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int bfs(vector<pair<int, int>> currents, int h, int w, vector<vector<pair<int, int>>>& warp, vector<string>& S, vector<vector<bool>>& is_visited, int dist) {

    vector<int> direct_r = {-1, 1, 0, 0};
    vector<int> direct_c = {0, 0, -1, 1};

    vector<pair<int, int>> nexts;
    for (auto [r, c] : currents) {
        // ４方向を調べる
        rep (i, 4) {
            int next_r = r + direct_r[i];
            int next_c = c + direct_c[i];
            if (next_r == -1 || next_r == h || next_c == -1 || next_c == w) {
                continue;
            }

            if (next_r == h - 1 && next_c == w - 1) {
                return dist;
            }

            if (is_visited[next_r][next_c] || S[next_r][next_c] == '#') {
                continue;
            }
            is_visited[next_r][next_c] = true;
            nexts.push_back({next_r, next_c});
        }
        // ワープ先を調べる
        if (S[r][c] != '#' && S[r][c] != '.') {
            for (auto [warp_r, warp_c] : warp[S[r][c]]) {
                if (warp_r == r && warp_c == c) {
                    continue;
                }

                if (warp_r == h - 1 && warp_c == w - 1) {
                    return dist;
                }

                if (is_visited[warp_r][warp_c]) {
                    continue;
                }
                is_visited[warp_r][warp_c] = true;
                nexts.push_back({warp_r, warp_c});
            }
            warp[S[r][c]].clear();
        }
    }
    debug(nexts);

    if(nexts.empty()) {
        return -1;
    }

    return bfs(nexts, h, w, warp, S, is_visited, dist + 1);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w;
    cin >> h >> w;

    if (h == 1 && w == 1) {
        cout << 0 << '\n';
        return 0;
    }

    // char をインデックスとして扱う
    vector<vector<pair<int, int>>> warp(256);
    vector<string> S(h);

    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) {
            if (s[j] != '#' && s[j] != '.') {
                warp[s[j]].push_back({i, j});
            }
        }
        S[i] = s;
    }
    //debug(warp['y']);
    //debug(S);

    vector<vector<bool>> is_visited(h, vector<bool>(w, false));
    is_visited[0][0] = true;

    cout << bfs({{0, 0}}, h, w, warp, S, is_visited, 1) << '\n';

    return 0;
}