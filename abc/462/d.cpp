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

    int length = 1000001;

    int n, d;
    cin >> n >> d;
    vector<int> S(n), T(n);
    rep (i, n) cin >> S[i] >> T[i];

    vector<vector<int>> add(length+1), del(length+1);
    rep (i, n) {
        if (T[i] - S[i] < d) {
            continue;
        }

        add[S[i]+d].push_back(i);
        del[T[i]].push_back(i);
    }
    //debug(add);
    //debug(del);

    set<int> cp;
    ll count = 0;
    rep (i, length) {
        for (int j : add[i+1]) {
            cp.insert(j);
        }
        count += 1LL * cp.size() * (cp.size() - 1) / 2;
        for (int j : del[i+1]) {
            cp.erase(j);
        }
    }
    cout << count << '\n';

    return 0;
}