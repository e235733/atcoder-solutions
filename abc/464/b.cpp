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

    int h, w;
    cin >> h >> w;

    vector<string> S(h);
    rep (i, h) cin >> S[i];

    set<int> r, c;
    rep (i, h) {
        bool all_w = true;
        rep (j, w) {
            if (S[i][j] == '#') {
                all_w = false;
                break;
            }
        }
        if (all_w) r.insert(i);
        else break;
    }
    rep (i, h) {
        bool all_w = true;
        rep (j, w) {
            if (S[h-i-1][j] == '#') {
                all_w = false;
                break;
            }
        }
        if (all_w) r.insert(h-i-1);
        else break;
    }
    rep (i, w) {
        bool all_w = true;
        rep (j, h) {
            if (S[j][i] == '#') {
                all_w = false;
                break;
            }
        }
        if (all_w) c.insert(i);
        else break;
    }
    rep (i, w) {
        bool all_w = true;
        rep (j, h) {
            if (S[j][w-i-1] == '#') {
                all_w = false;
                break;
            }
        }
        if (all_w) c.insert(w-i-1);
        else break;
    }

    rep (i, h) {
        if (r.contains(i)) continue;
        rep (j, w) {
            if (c.contains(j)) continue;
            cout << S[i][j];
        }
        cout << '\n';
    }


    return 0;
}