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

    int n, t;
    cin >> n >> t;

    vector<ll> P(n+1, 0);
    map<ll, int> pc;
    pc[0] = n;
    rep (_, t) {
        int a;
        ll b;
        cin >> a >> b;

        --pc[P[a]];
        if (!pc[P[a]]) pc.erase(P[a]);

        P[a] += b;
        ++pc[P[a]];

        cout << pc.size() << '\n';
    }

    return 0;
}