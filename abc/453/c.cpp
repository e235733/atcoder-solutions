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

    int n;
    cin >> n;

    vector<pair<ll, int>> current({{1, 0}});
    int len_vector = 1;

    rep (i, n) {
        vector<pair<ll, int>> next;
        ll l;
        cin >> l;
        l *= 2;

        len_vector *= 2;
        next.reserve(len_vector);
        for (auto p : current) {
            ll n_p0 = p.first + l;
            ll n_p1 = p.first - l;

            if ((n_p0 > 0 && p.first < 0) || (n_p0 < 0 && p.first > 0)) {
                next.push_back({n_p0, p.second+1});
            }
            else {
                next.push_back({n_p0, p.second});
            }

            if ((n_p1 > 0 && p.first < 0) || (n_p1 < 0 && p.first > 0)) {
                next.push_back({n_p1, p.second+1});
            }
            else {
                next.push_back({n_p1, p.second});
            }
        }
        //debug(next);
        current = next;
    }

    int max_score = 0;
    rep (i, len_vector) {
        max_score = max(max_score, current[i].second);
    }
    cout << max_score << '\n';

    return 0;
}