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

    int q, v;
    cin >> q >> v;
    priority_queue<int> pq;
    rep (_, q) {
        int k;
        cin >> k;
        if (k == 1) {
            int t, w;
            cin >> t >> w;
            pq.push(w-t);
        }
        else if (k == 2) {
            int t;
            cin >> t;
            if (!pq.size()) {
                cout << -1 << '\n';
                continue;
            }

            int m = pq.top();
            pq.pop();
            cout << min(v, m+t) << '\n';
        }
    }

    return 0;
}