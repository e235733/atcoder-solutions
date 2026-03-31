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

    int h, w, rs, cs, rt, ct;
    cin >> h >> w >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;

    vector<vector<char>> s(h, vector<char>(w));
    rep (i, h) {
        rep (j, w) {
            cin >> s[i][j];
        }
    }
    debug(s);

    
    // 幅優先探索する
    vector<pair<int, int>> currents = {{rs, cs}};
    // count がいくつのときに訪れたかを記録
    vector<vector<int>> is_visited_when(h, vector<int>(w, -1));
    is_visited_when[rs][cs] = 0;
    int count = 0;
    while (true) {
        debug(count, currents);
        vector<pair<int, int>> nexts;
        for (pair p : currents) {
            debug(p);
            // 各方向に伸ばせるだけのばす
            int t_r = p.first - 1;
            while (t_r != -1) {
                debug(t_r, p.second);
                int &when = is_visited_when[t_r][p.second];
                if (s[t_r][p.second] == '#' || (when != -1 && when < count)) {
                    break;
                }
                // 到達判定
                if (t_r == rt && p.second == ct) {
                    cout << count << '\n';
                    return 0;
                }
                when = count;
                nexts.push_back({t_r, p.second});
                t_r--;
            }
            int b_r = p.first + 1;
            while (b_r != h) {
                debug(b_r, p.second);
                int &when = is_visited_when[b_r][p.second];
                if (s[b_r][p.second] == '#' || (when != -1 && when < count)) {
                    break;
                }
                // 到達判定
                if (b_r == rt && p.second == ct) {
                    cout << count << '\n';
                    return 0;
                }
                when = count;
                nexts.push_back({b_r, p.second});
                b_r++;
            }
            int l_c = p.second - 1;
            while (l_c != -1) {
                debug(p.first, l_c);
                int &when = is_visited_when[p.first][l_c];
                if (s[p.first][l_c] == '#' || (when != -1 && when < count)) {
                    break;
                }
                // 到達判定
                if (p.first == rt && l_c == ct) {
                    cout << count << '\n';
                    return 0;
                }
                when = count;
                nexts.push_back({p.first, l_c});
                l_c--;
            }
            int r_c = p.second + 1;
            while (r_c != w) {
                debug(p.first, r_c);
                int &when = is_visited_when[p.first][r_c];
                if (s[p.first][r_c] == '#' || (when != -1 && when < count)) {
                    break;
                }
                // 到達判定
                if (p.first == rt && r_c == ct) {
                    cout << count << '\n';
                    return 0;
                }
                when = count;
                nexts.push_back({p.first, r_c});
                r_c++;
            }
        }
        currents = nexts;
        count++;
    }

    return 0;
}