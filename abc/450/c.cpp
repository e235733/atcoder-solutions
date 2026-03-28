#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

bool dfs(int r, int c, const vector<string> &S, vector<vector<bool>> &is_visited, int h, int w) {
    is_visited[r][c] = true;
    
    bool is_valid = true;
    
    if (r == 0 || r == h - 1 || c == 0 || c == w - 1) {
        is_valid = false;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    rep(i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
            if (S[nr][nc] == '.' && !is_visited[nr][nc]) {
                
                bool child_valid = dfs(nr, nc, S, is_visited, h, w);
                
                if (!child_valid) {
                    is_valid = false;
                }
            }
        }
    }
    return is_valid;
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

    // 探索済みリスト
    vector<vector<bool>> is_visited(h, vector<bool>(w, false));
    int result = 0;
    rep (i, h) {
        rep (j, w) {
            debug(i, j);
            if (S[i][j] == '.' && !is_visited[i][j]) {
                if (dfs(i, j, S, is_visited, h, w)) {
                    result++;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}