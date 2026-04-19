#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs(vector<string>& S, vector<vector<bool>>& used, int r, int c, int s_r, int s_c, int count, int& max_count, int h, int w) {
    debug(r, c);

    vector<int> d_r = {-1, 1, 0, 0};
    vector<int> d_c = {0, 0, -1, 1};

    rep (i, 4) {
        int n_r = r + d_r[i];
        int n_c = c + d_c[i];
        if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) {
            continue;
        }

        if (n_r == s_r && n_c == s_c && count > 2) {
            debug(count);
            max_count = max(max_count, count+1);
            return;
        }

        if (used[n_r][n_c] || S[n_r][n_c] == '#') {
            continue;
        }
        used[n_r][n_c] = true;
        dfs(S, used, n_r, n_c, s_r, s_c, count+1, max_count, h, w);
        used[n_r][n_c] = false;
    }
}

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

    vector<vector<bool>> used(h, vector<bool>(w, false));
    int max_count = -1;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') {
                continue;
            }
            used[i][j] = true;
            dfs(S, used, i, j, i, j, 0, max_count, h, w);
            used[i][j] = false;
        }
    }
    
    cout << max_count << '\n';

    return 0;
}