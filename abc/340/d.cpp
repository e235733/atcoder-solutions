#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    int to;
    ll w;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<vector<edge>> G(n+1);
    rep (i, n-1) {
        ll a, b;
        int x;
        cin >> a >> b >> x;

        G[i+1].push_back({i+2, a});
        G[i+1].push_back({x, b});
    }

    vector<ll> mw(n+1, 1LL<<60);
    mw[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (pq.size()) {
        auto [tw, i] = pq.top();
        pq.pop();

        if (tw > mw[i]) continue;

        for (auto [to, w] : G[i]) {
            ll nw = tw + w;
            if (nw >= mw[to]) continue;

            mw[to] = nw;
            pq.push({nw, to});
        }
    }

    cout << mw[n] << '\n';

    return 0;
}