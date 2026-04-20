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

    int n, m;
    cin >> n >> m;

    vector<int> x(m), a(m);
    rep (i, m) {
        cin >> x[i];
    }
    rep (i, m) {
        cin >> a[i];
    }
    
    map<int, int> g;
    rep (i, m) {
        g[x[i]] = a[i];
    }
    debug(g);

    if (!g.contains(1)) {
        cout << -1 << '\n';
        return 0;
    }

    auto it = g.rbegin();
    ll p_x = n + 1;
    ll count = 0;
    while (it != g.rend()) {
        ll c_x = it->first;
        ll c_a = it->second;
        debug(p_x, c_x, c_a);

        ll d_x = p_x - c_x - 1;
        if (d_x + 1 == c_a) {
            count += (d_x + 1) * d_x / 2;
            p_x = c_x;
        }
        else if (d_x >= c_a){
            count += (d_x + d_x - c_a + 1) * c_a / 2;
            p_x -= c_a;
        }
        else {
            cout << -1 << '\n';
            return 0;
        }
        it++;
    }
    if (p_x == 1) {
        cout << count << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}