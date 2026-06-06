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

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> S(h);
    rep (i, h) {
        cin >> S[i];
    }

    vector<vector<int>> sone(h+1, vector<int>(w+1, 0));
    rep (i, h) {
        rep (j, w) {
            if (S[i][j] == '1') {
                sone[i+1][j+1] = sone[i][j+1] + 1;
            }
            else {
                sone[i+1][j+1] = sone[i][j+1];
            }
        }
    } 
    rep (i, h) {
        rep (j, w) {
            sone[i+1][j+1] += sone[i+1][j];
        }
    } 
    debug(sone);

    ll count = 0;
    for (int ei=1; ei!=h+1; ++ei) {
        for (int ej=1; ej!=w+1; ++ej) {
            rep (si, ei) {
                rep (sj, ej) {
                    if (sone[ei][ej] - sone[ei][sj] - sone[si][ej] + sone[si][sj] == k) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << '\n';

    return 0;
}