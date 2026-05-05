#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

struct edge {
    ll cost;
    int to;
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
    int s_x, s_y;
    ll s_c;
    rep (i, m) {
        int x, y;
        ll c;
        cin >> x >> y >> c;
        if (i == 0) {
            s_x = x;
            s_y = y;
            s_c = c;
        }
        else {
            g[x].push_back({c, y});
        }
    }

    if (s_x == s_y) {
        cout << s_c << '\n';
        return 0;
    }

    vector<ll> min_cost(n+1, 1000000000000000000);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    min_cost[s_y] = s_c;
    pq.push({s_c, s_y});
    while (pq.size()) {
        auto [cost, x] = pq.top();
        debug(cost, x);
        pq.pop();

        if (min_cost[x] < cost) {
            continue;
        }
        if (x == s_x) {
            cout << cost << '\n';
            return 0;
        }

        for (edge e : g[x]) {
            ll next_cost = cost + e.cost;
            debug(next_cost, e.to);
            if (next_cost < min_cost[e.to]) {
                min_cost[e.to] = next_cost;
                pq.push({next_cost, e.to});
            }    
        }
    }
    cout << -1 << '\n';

    return 0;
}