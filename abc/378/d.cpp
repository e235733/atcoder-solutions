#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

void dfs (vector<string>& S, vector<vector<bool>>& used, int r, int c, int dist, int k, int& count, int h, int w) {
    if (dist == k) {
        count++;
        return;
    }
    
    vector<int> d_r = {-1, 1, 0, 0};
    vector<int> d_c = {0, 0, -1, 1};

    rep (i, 4) {
        int n_r = r + d_r[i];
        int n_c = c + d_c[i];

        if (n_r < 0 || n_r >= h || n_c < 0 || n_c >= w) {
            continue;
        }
        if (S[n_r][n_c] == '#' || used[n_r][n_c]) {
            continue;
        }

        used[n_r][n_c] = true;
        dfs(S, used, n_r, n_c, dist+1, k, count, h, w);
        used[n_r][n_c] = false;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> S(h);
    rep (i, h) {
        cin >> S[i];
    }

    vector<vector<bool>> used(h, vector<bool>(w, false));
    int count = 0;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') {
                continue;
            }

            used[i][j] = true;
            dfs(S, used, i, j, 0, k, count, h, w);
            used[i][j] = false;
        }
    }
    cout << count << '\n';

    return 0;
}