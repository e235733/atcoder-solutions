#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

map<int, int> fab;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, k;
    cin >> n >> k;
    int ml = -1;
    vector<pair<int, int>> rl(n);
    rep (i, n) {
        int l, r;
        cin >> l >> r;
        rl[i] = {r, l};
    }
    sort(rl.begin(), rl.end());
    debug(rl);

    rep (i, n) {
        if (rl[i].second > ml) {
            fab[rl[i].second] = rl[i].first;
            ml = rl[i].second;
        }
    }
    debug(fab);

    int ok = -1;
    int ng = 1 << 30;
    while (ok + 1 < ng) {
        int mid = (ok + ng) / 2;
        int pr = fab.begin()->second;
        bool complete = true;
        rep (i, k-1) {
            auto it = fab.upper_bound(pr+mid);
            if (it == fab.end()) {
                complete = false;
                break;
            }
            pr = it->second;
        }
        if (complete) ok = mid;
        else ng = mid;
    }
    debug(ok);

    if (ok != -1) cout << ok + 1 << '\n';
    else cout << -1 << '\n';

    return 0;
}