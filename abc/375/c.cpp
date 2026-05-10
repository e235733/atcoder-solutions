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

    vector<string> S(n);
    rep (i, n) {
        cin >> S[i];
    }

    vector<vector<char>> T(n, vector<char>(n));
    rep (i, n/2) {
        if (i % 4 == 0) {
            rep (x, n-i*2) {
                T[i][n-1-i-x] = S[x+i][i];
                T[n-1-i][n-1-i-x] = S[x+i][n-1-i];
            }
            rep (y, n-i*2) {
                T[y+i][n-1-i] = S[i][y+i];
                T[y+i][i] = S[n-1-i][y+i];
            }
        }
        else if (i % 4 == 1) {
            rep (x, n-i*2) {
                T[n-1-i-x][n-1-i] = S[x+i][i];
                T[n-1-i-x][i] = S[x+i][n-1-i];
            }
            rep (y, n-i*2) {
                T[n-1-i][n-1-i-y] = S[i][y+i];
                T[i][n-1-i-y] = S[n-1-i][y+i];
            }
        }
        else if (i % 4 == 2) {
            rep (x, n-i*2) {
                T[n-1-i][x+i] = S[x+i][i];
                T[i][x+i] = S[x+i][n-1-i];
            }
            rep (y, n-i*2) {
                T[n-1-i-y][i] = S[i][y+i];
                T[n-1-i-y][n-1-i] = S[n-1-i][y+i];
            }
        }
        else if (i % 4 == 3) {
            rep (x, n-i*2) {
                T[x+i][i] = S[x+i][i];
                T[x+i][n-1-i] = S[x+i][n-1-i];
            }
            rep (y, n-i*2) {
                T[i][y+i] = S[i][y+i];
                T[n-1-i][y+i] = S[n-1-i][y+i];
            }
        }
    }

    rep (i, n) {
        rep (j, n) {
            cout << T[i][j];
        }
        cout << '\n';
    }

    return 0;
}