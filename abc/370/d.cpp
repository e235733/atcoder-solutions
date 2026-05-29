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

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> wc(h+1), wr(w+1);
    rep (i, h) {
        rep (j, w) {
            wc[i+1].insert(j+1);
            wr[j+1].insert(i+1);
        }
    }
    debug(wc);
    debug(wr);

    vector<vector<bool>> e(h+1, vector<bool>(w+1, true));

    rep (_, q) {
        int r, c;
        cin >> r >> c;
        debug(r, c);

        if (e[r][c]) {
            e[r][c] = false;
            wc[r].erase(c);
            wr[c].erase(r);
            continue;
        }

        int eu = 0;
        int ed = 0;
        int el = 0;
        int er = 0;
        auto itr = wc[r].upper_bound(c);
        if (itr != wc[r].end()) {
            er = *itr;
        }
        if (itr != wc[r].begin()) {
            itr--;
            el = *itr;
        }

        auto itd = wr[c].upper_bound(r);
        if (itd != wr[c].end()) {
            ed = *itd;
        }
        if (itd != wr[c].begin()) {
            itd--;
            eu = *itd;
        }

        if (eu != 0) {
            e[eu][c] = false;
            wc[eu].erase(c);
            wr[c].erase(eu);
        }
        if (ed != 0) {
            e[ed][c] = false;
            wc[ed].erase(c);
            wr[c].erase(ed);
        }
        if (el != 0) {
            e[r][el] = false;
            wc[r].erase(el);
            wr[el].erase(r);
        }
        if (er != 0) {
            e[r][er] = false;
            wc[r].erase(er);
            wr[er].erase(r);
        }
    }

    int count = 0;
    rep (i, h) {
        rep (j, w) {
            if (e[i+1][j+1]) {
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}