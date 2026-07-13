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

    int n;
    cin >> n;
    vector<string> S(n);
    rep (i, n) cin >> S[i];
    int sr1 = -1, sc1 = -1, sr2 = -1, sc2 = -1;
    rep (i, n) {
        rep (j, n) {
            if (S[i][j] == 'P') {
                if (sr1 == -1) {
                    sr1 = i;
                    sc1 = j;
                }
                else {
                    sr2 = i;
                    sc2 = j;
                }
            }
        }
    }

    vector<int> mc(n*n*n*n, -1);
    mc[(sr1*n+sc1)*n*n+sr2*n+sc2] = 0;
    vector<int> P = {(sr1*n+sc1)*n*n+sr2*n+sc2};
    int count = 0;
    while (P.size()) {
        debug(P);
        ++count;
        debug(count);
        vector<int> Q;
        for (int p : P) {
            int r1 = p / n / n / n;
            int c1 = p / n / n % n;
            int r2 = p % (n * n) / n;
            int c2 = p % (n * n) % n;
            debug(r1, c1, r2, c2);

            rep (i, 4) {
                int nr1 = r1 + dr[i], nc1 = c1 + dc[i], nr2 = r2 + dr[i], nc2 = c2 + dc[i];

                if (nr1 == -1 || nr1 == n || nc1 == -1 || nc1 == n) nr1 = r1, nc1 = c1;
                else if (S[nr1][nc1] == '#') nr1 = r1, nc1 = c1;

                if (nr2 == -1 || nr2 == n || nc2 == -1 || nc2 == n) nr2 = r2, nc2 = c2;
                else if (S[nr2][nc2] == '#') nr2 = r2, nc2 = c2;

                int v1 = nr1 * n + nc1, v2 = nr2 * n + nc2;
                int uv = min(v1, v2), dv = max(v1, v2);
                int v = uv*n*n+dv;
                if (mc[v] == -1) {
                    mc[v] = count;
                    Q.push_back(v);
                }
            }
        }
        swap(P, Q);
    }

    int ans = 1<<30;
    rep (i, n) {
        rep (j, n) {
            int u = i * n + j;
            if (mc[u*n*n+u] != -1) {
                ans = min(ans, mc[u*n*n+u]);
            }
        }
    }

    if (ans == 1<<30) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}