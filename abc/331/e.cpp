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

    ll n, m, l;
    cin >> n >> m >> l;

    vector<pair<int, ll>> Ai(n), Bi(m);
    rep (i, n) {
        int a;
        cin >> a;
        Ai[i] = {a, i};
    }
    rep (i, m) {
        int b;
        cin >> b;
        Bi[i] = {b, i};
    }

    sort(Ai.rbegin(), Ai.rend());
    sort(Bi.rbegin(), Bi.rend());
    debug(Ai, Bi);

    set<ll> ban;
    rep (_, l) {
        ll c, d;
        cin >> c >> d;
        --c, --d;

        ban.insert(c * m + d);
    }
    debug(ban);

    set<ll> used;
    used.insert(0);
    priority_queue<pair<int, ll>> pq;
    pq.push({Ai[0].first+Bi[0].first, 0});
    while (pq.size()) {
        auto [s, v] = pq.top();
        pq.pop();

        ll i = v / m;
        ll j = v % m;

        if (!ban.contains(Ai[i].second*m+Bi[j].second)) {
            cout << s << '\n';
            return 0;
        }

        if (i != n-1) {
            ll nv1 = (i + 1) * m + j;
            if (!used.contains(nv1)) {
                used.insert(nv1);
                pq.push({Ai[i+1].first+Bi[j].first, nv1});
            }
        }
        if (j != m-1) {
            ll nv2 = i * m + j + 1;
            if (!used.contains(nv2)) {
                used.insert(nv2);
                pq.push({Ai[i].first+Bi[j+1].first, nv2});
            }
        }
    }

    return 0;
}