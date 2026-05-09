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

    int t;
    cin >> t;

    rep (_, t) {
        int n, k;
        cin >> n >> k;

        vector<ll> A(n), B(n);
        rep (i, n) {
            cin >> A[i];
        }
        rep (i, n) {
            cin >> B[i];
        }

        vector<pair<ll, ll>> vec(n);
        rep (i, n) {
            vec[i] = {A[i], B[i]};
        }
        sort(vec.begin(), vec.end());
        debug(vec);

        priority_queue<ll> pq;
        ll sum_b = 0;
        rep (i, k) {
            pq.push(vec[i].second);
            sum_b += vec[i].second;
        }
        ll max_a = vec[k-1].first;

        ll result = max_a * sum_b;
        for (int i=k; i!=n; ++i) {
            debug(pq);
            debug(result);
            max_a = vec[i].first;
            ll max_b = pq.top();
            ll b = vec[i].second;
            debug(max_a, max_b, b);
            if (b >= max_b) {
                continue;
            }

            sum_b += b - max_b;
            result = min(result, max_a * sum_b);
            pq.pop();
            pq.push(b);
        }
        cout << result << '\n';
    }

    return 0;
}