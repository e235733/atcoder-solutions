#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int h, w;

vector<string> S(1000);

vector used(1000, vector<bool>(1000, false));
int ans = 0;

int dfs (int r, int c, set<pair<int, int>> &used_at) {
    if (S[r][c] == '@') return 1;

    int count = 0;
    rep (i, 4) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr == -1 || nr == h || nc == -1 || nc == w) continue;
        if (S[nr][nc] == '#') continue;
        else if (S[nr][nc] == '@') {
            if (used_at.contains({nr, nc})) continue;
            used_at.insert({nr, nc});
        }
        else {
            if (used[nr][nc]) continue;
            used[nr][nc] = true;
        }

        count += dfs(nr, nc, used_at);
    }

    return count + 1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> h >> w;
    rep (i, h) cin >> S[i];

    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#') continue;

            rep (k, 4) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (nr == -1 || nr == h || nc == -1 || nc == w) continue;
                if (S[nr][nc] == '#') {
                    S[i][j] = '@';
                    break;
                }
            }
        }
    }

    int ans = 1;
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '#' || S[i][j] == '@') continue;
            if (used[i][j]) continue;
            used[i][j] = true;
            set<pair<int, int>> used_at;
            ans = max(ans, dfs(i, j, used_at));
        }
    }

    cout << ans << '\n';

    return 0;
}