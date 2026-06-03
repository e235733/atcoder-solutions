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

    int n;
    cin >> n;
    vector<vector<vector<int>>> A(n, vector<vector<int>>(n, vector<int>(n)));
    rep (i, n) {
        rep (j, n) {
            rep (k, n) {
                cin >> A[i][j][k];
            }
        }
    }
    debug(A);

    vector<vector<vector<int>>> S(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    rep (i, n) {
        rep (j, n) {
            rep (k, n) {
                S[i+1][j+1][k+1] = S[i+1][j+1][k] + A[i][j][k];
            }
        }
    }
    rep (i, n) {
        rep (j, n) {
            rep (k, n) {
                S[i+1][j+1][k+1] += S[i+1][j][k+1];
            }
        }
    }
    rep (i, n) {
        rep (j, n) {
            rep (k, n) {
                S[i+1][j+1][k+1] += S[i][j+1][k+1];
            }
        }
    }
    debug(S);

    int q;
    cin >> q;
    rep (_, q) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        cout << S[rx][ry][rz] - S[lx-1][ry][rz] - S[rx][ly-1][rz] - S[rx][ry][lz-1] + S[lx-1][ly-1][rz] + S[lx-1][ry][lz-1] + S[rx][ly-1][lz-1] - S[lx-1][ly-1][lz-1] << '\n';
    }

    return 0;
}