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

    int h, w, n;
    cin >> h >> w >> n;

    vector S(h, vector<char>(w, '.'));

    int d = 0;
    int r = 0, c = 0;
    rep (_, n) {
        if (S[r][c] == '.') {
            S[r][c] = '#';
            d = (d + 1) % 4;
            r += dr[d];
            c += dc[d];
            r = (r + h) % h;
            c = (c + w) % w;
        }
        else if (S[r][c] == '#') {
            S[r][c] = '.';
            d = (d + 3) % 4;
            r += dr[d];
            c += dc[d];
            r = (r + h) % h;
            c = (c + w) % w; 
        }
    }

    rep (i, h) {
        rep (j, w) {
            cout << S[i][j];
        }
        cout << '\n';
    }

    return 0;
}