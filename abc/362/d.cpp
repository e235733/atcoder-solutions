#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

ll INF = 1LL << 60;

int n, m;
vector<ll> A(200001);

struct edge {
    int to;
    ll b;
};

vector<vector<edge>> g(200001);
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
vector<ll> mw(200001, INF);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    rep (i, n) cin >> A[i+1];
    
    rep (_, m) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        g[u].push_back({v, b*2+A[u]+A[v]});
        g[v].push_back({u, b*2+A[u]+A[v]});
    }

    pq.push({A[1], 1});
    mw[1] = A[1];

    while (pq.size()) {
        auto [cw, ce] = pq.top();
        debug(cw, ce);
        pq.pop();

        if (cw > mw[ce]) continue;

        for (auto [to, b] : g[ce]) {
            debug(to, b);
            ll nw = cw + b;
            if (nw < mw[to]) {
                mw[to] = nw;
                debug(to, mw[to]);
                pq.push({nw, to});
            }
        }
    }

    rep (i, n-1) cout << (mw[i+2] + A[i+2]) / 2 << ' ';
    cout << '\n';

    return 0;
}