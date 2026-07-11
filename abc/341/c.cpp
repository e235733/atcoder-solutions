#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int h, w, n;
    string t;
    cin >> h >> w >> n >> t;
    vector<string> S(h);
    rep (i, h) cin >> S[i];

    int ans = 0;
    rep (sr, h) {
        rep (sc, w) {
            if (S[sr][sc] == '#') continue;

            bool ok = true;
            int r = sr;
            int c = sc;
            rep (i, n) {
                int d = -1;
                if (t[i] == 'U') d = 0;
                else if (t[i] == 'D') d = 1;
                else if (t[i] == 'R') d = 2;
                else if (t[i] == 'L') d = 3;

                r += dr[d];
                c += dc[d];

                if (S[r][c] == '#') {
                    ok = false;
                    break;
                }
            }

            if (ok) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}