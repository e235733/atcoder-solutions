#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct Parent {
    int r, c, d;
    char m;
};

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

    int s_r, s_c, g_r, g_c;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == 'S') {
                s_r = i;
                s_c = j;
            }
            else if (S[i][j] == 'G') {
                g_r = i;
                g_c = j;
            }
        }
    }

    vector<pair<pair<int, int>, int>> current({{{s_r, s_c}, -1}});

    vector<vector<bool>> used_d(h, vector<bool>(w, false));
    used_d[s_r][s_c] = true;

    // 0:U, 1:D, 2:L, 3:R
    vector<vector<vector<bool>>> used_o(h, vector<vector<bool>>(w, vector<bool>(4, false)));
    vector<vector<vector<bool>>> used_x(h, vector<vector<bool>>(w, vector<bool>(4, false)));

    vector<vector<vector<Parent>>> parent(h, vector<vector<Parent>>(w, vector<Parent>(4)));

    string s_d = "UDLR";

    vector<int> d_r = {-1, 1, 0, 0};
    vector<int> d_c = {0, 0, -1, 1};

    while (current.size()) {
        debug(current);
        vector<pair<pair<int, int>, int>> next;
        
        for (auto p : current) {
            int r = p.first.first;
            int c = p.first.second;
            int in_dir = p.second;
            debug(r, c, in_dir);

            if (r == g_r && c == g_c) {
                string s = "";
                int cr = r, cc = c, cd = in_dir;
                while (cd != -1) {
                    Parent p_node = parent[cr][cc][cd];
                    s += p_node.m;
                    cr = p_node.r;
                    cc = p_node.c;
                    cd = p_node.d;
                }
                reverse(s.begin(), s.end());

                cout << "Yes" << '\n' << s << '\n';
                return 0;
            }

            vector<int> current_d;
            if (S[r][c] == 'o') {
                char prev_d = s_d[in_dir];
                current_d.reserve(1);
                rep (i, 4) {
                    if (s_d[i] == prev_d) {
                        current_d.push_back(i);
                    }
                }
            }
            else if (S[r][c] == 'x') {
                char prev_d = s_d[in_dir];
                current_d.reserve(3);
                rep (i, 4) {
                    if (s_d[i] != prev_d) {
                        current_d.push_back(i);
                    }
                }
            }
            else {
                current_d.reserve(4);
                rep (i, 4) {
                    current_d.push_back(i);
                }
            }

            for (int i : current_d) {
                int n_r = r + d_r[i];
                int n_c = c + d_c[i];

                if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) {
                    continue;
                }
                if (S[n_r][n_c] == '#') {
                    continue;
                }
                else if (S[n_r][n_c] == 'o') {
                    if (used_o[n_r][n_c][i]) {
                        continue;
                    }
                    used_o[n_r][n_c][i] = true;
                }
                else if (S[n_r][n_c] == 'x') {
                    if (used_x[n_r][n_c][i]) {
                        continue;
                    }
                    used_x[n_r][n_c][i] = true;
                }
                else {
                    if (used_d[n_r][n_c]) {
                        continue;
                    }
                    used_d[n_r][n_c] = true;
                }
                
                parent[n_r][n_c][i] = {r, c, in_dir, s_d[i]};
                
                next.push_back({{n_r, n_c}, i});
            }
        }
        current = next;
    }
    cout << "No" << '\n';

    return 0;
}