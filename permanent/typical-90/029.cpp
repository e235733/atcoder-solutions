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

    int w, n;
    cin >> w >> n;
    map<int, int> hf;
    hf[1] = 0;

    rep (i, n) {
        int l, r;
        cin >> l >> r;

        auto il = hf.lower_bound(l);
        auto ir = hf.upper_bound(r);
        if (il == ir) {
            il--;
            int ch = il->second;

            cout << ch + 1 << '\n';

            hf[l] = ch + 1;
            if (ir->first != r+1) {
                hf[r+1] = ch;
            }
        }
        else {
            if (il->first != l) {
                il--;
            }
            int mh = 0;
            vector<int> del;
            int lh;
            while (il != ir) {
                mh = max(il->second, mh);
                if (il->first >= l) {
                    del.push_back(il->first);
                }
                lh = il->second;
                il++;
            }

            for (int d : del) {
                hf.erase(d);
            }

            cout << mh + 1 << '\n';

            hf[l] = mh + 1;
            if (ir->first != r+1) {
                hf[r+1] = lh;
            }
        }

        debug(hf);
    }

    return 0;
}