#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    int to;
    int cost;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    int n, m;
    cin >> n >> m;

    vector<vector<edge>> g(n+1);
    rep (_, m) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> mc(n+1, 1000000000);
    mc[1] = 0;
    for (edge e : g[1]) {
        pq.push({e.cost, e.to});
        debug(e.cost, e.to);
        mc[e.to] = e.cost;
    }

    while (pq.size()) {
        auto[c, e] = pq.top();
        debug(pq.top());
        pq.pop();

        for (edge ne : g[e]) {
            int nto = ne.to;
            int nc = c + ne.cost;
            debug(nto, nc);

            if (nc < mc[nto]) {
                mc[nto] = nc;
                pq.push({nc, nto});
            }
        }
    }

    vector<int> rmc(n+1, 1000000000);
    rmc[n] = 0;
    for (edge e : g[n]) {
        pq.push({e.cost, e.to});
        debug(e.cost, e.to);
        rmc[e.to] = e.cost;
    }
    while (pq.size()) {
        auto[c, e] = pq.top();
        debug(pq.top());
        pq.pop();

        for (edge ne : g[e]) {
            int nto = ne.to;
            int nc = c + ne.cost;
            debug(nto, nc);

            if (nc < rmc[nto]) {
                rmc[nto] = nc;
                pq.push({nc, nto});
            }
        }
    }

    rep(i, n) {
        cout << mc[i+1] + rmc[i+1] << '\n';
    }

    return 0;
}