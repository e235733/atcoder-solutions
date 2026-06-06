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

    int n, k, m;
    cin >> n >> k >> m;

    vector<pair<ll, int>> vc(n);
    unordered_map<int, int> lc;
    rep (i, n) {
        int c;
        ll v;
        cin >> c >> v;
        vc[i] = {v, c};
        lc[c]++;
    }
    sort(vc.rbegin(), vc.rend());
    debug(vc);

    ll sv = 0;
    unordered_set<int> cset;
    int count = 0;
    rep (i, n) {
        debug(vc[i]);
        debug(cset);
        debug(count);
        if (count == k) break;
        if ((int)cset.size() >= m) {
            sv += vc[i].first;
            count++;
            cset.insert(vc[i].second);
        }
        else {
            if (k - count == m - (int)cset.size()) {
                if (!cset.contains(vc[i].second)) {
                    sv += vc[i].first;
                    cset.insert(vc[i].second);
                    count++;   
                }
            }
            else {
                cset.insert(vc[i].second);
                sv += vc[i].first;
                count++;
            }
        }
        lc[vc[i].second]--;
        if (lc[vc[i].second] == 0) {
            lc.erase(vc[i].second);
        }
    }

    cout << sv << '\n';

    return 0;
}