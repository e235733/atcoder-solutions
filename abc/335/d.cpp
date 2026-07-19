#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;

    vector S(n, vector<string>(n, "."));
    S[n/2][n/2] = "T";

    int cr = n / 2 - 1;
    int cc = n / 2;
    int cd = 0;
    rep (i, n*n-1) {
        S[cr][cc] = to_string(i+1);

        int cu = 0;
        rep (j, 4) {
            int nr = cr + dr[j];
            int nc = cc + dc[j];
            if (nr == -1 || nr == n || nc == -1 || nc == n) continue;
            if (S[nr][nc] != ".") ++cu;
        }

        if (cu % 2 == 1) {
            cd = (cd + 1) % 4;
        }

        cr += dr[cd];
        cc += dc[cd];
    }

    debug(S);

    rep (i, n) {
        rep (j, n) {
            cout << S[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}