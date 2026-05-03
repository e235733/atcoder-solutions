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
        ll n, k, l;
        cin >> n >> k >> l;
        set<ll> A;
        rep (i, n) {
            ll a;
            cin >> a;
            A.insert(a);
        }

        auto it = A.begin();
        ll d_b, d_e;
        ll prev = *it;
        d_b = *it;
        it++;
        vector<ll> dist;
        dist.reserve(A.size());
        dist.push_back(0);
        while (it != A.end()) {
            dist.push_back((*it - prev) / 2);
            prev = *it;
            ++it;
        }
        sort(dist.rbegin(), dist.rend());
        debug(dist);
        d_e = l - prev;
        debug(d_b, d_e);

        if (k == 1) {
            cout << max(dist[0], max(d_b, d_e)) << '\n';
            continue;
        }

        ll max_time = max(d_b, d_e) + (d_b + d_e) * (k - 1);
        ll sum_dist = 0;
        for (int i=0; i!=(int)dist.size()-1; ++i) {
            debug(max_time);
            if (i == k) {
                break;
            }
            else if (i == k - 1) {
                max_time = max(max_time, sum_dist + dist[i]);
            }
            else {
                sum_dist += dist[i];
                d_b += dist[i];
                d_e += dist[i];
                max_time = max(max_time, sum_dist + max(d_b, d_e) + (d_b + d_e) * (k - i - 2));
            }
        }

        cout << max_time << '\n';
    }

    return 0;
}