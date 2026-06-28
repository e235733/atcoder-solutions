#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int h, w, q;
    cin >> h >> w >> q;

    vector<pair<char, pair<int, int>>> xrc(q);
    rep (i, q) {
        int r, c;
        char x;
        cin >> r >> c >> x;
        xrc[i] = {x, {r, c}};
    }
    reverse(xrc.begin(), xrc.end());

    vector S(h, vector<char>(w, '.'));
    rep (i, q) {
        char x = xrc[i].first;
        int r = xrc[i].second.first;
        int c = xrc[i].second.second;
        for (int j=r-1; j!=-1; --j) {
            if (S[j][c-1] != '.') break;

            for (int k=c-1; k!=-1; --k) {
                if (S[j][k] != '.') break;

                S[j][k] = x;
            }
        }
    }
    for (int j=h-1; j!=-1; --j) {
        if (S[j][w-1] != '.') break;

        for (int k=w-1; k!=-1; --k) {
            if (S[j][k] != '.') break;

            S[j][k] = 'A';
        }
    }

    debug(S);
    rep (i, h) {
        rep (j, w) {
            cout << S[i][j];
        }
        cout << '\n';
    }

    return 0;
}