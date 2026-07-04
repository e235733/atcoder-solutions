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

    int h, w, m;
    cin >> h >> w >> m;
    vector<int> T(m), A(m), X(m);
    rep (i, m) cin >> T[i] >> A[i] >> X[i];

    set<int> r, c;
    map<int, ll> count;
    ll call = 0;
    for (int i=m-1; i!=-1; --i) {
        if (T[i] == 1) {
            if ((int)c.size() == w) continue;
            if (!r.contains(A[i])) {
                count[X[i]] += w - c.size();
                call += w - c.size();
                r.insert(A[i]);
            }
        }
        else if (T[i] == 2) {
            if ((int)r.size() == h) continue;
            if (!c.contains(A[i])) {
                count[X[i]] += h - r.size();
                call += h - r.size();
                c.insert(A[i]);
            }
        }
    }
    debug(count);
    debug(call);

    if (call != 1LL * h * w) {
        count[0] += 1LL * h * w - call;
    }

    cout << count.size() << '\n';
    for (auto [c, n] : count) {
        cout << c << ' ' << n << '\n';
    }

    return 0;
}