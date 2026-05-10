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

    string S;
    cin >> S;
    ll length = S.size();

    if (length < 3) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<pair<ll, ll>>> C(26, vector<pair<ll, ll>>(length+1, {0, 0}));
    rep (i, length) {
        rep (j, 26) {
            C[j][i+1] = C[j][i];
        }
        int n_c = S[i] - 'A';
        C[n_c][i+1].first += i;
        C[n_c][i+1].second++;
    }
    debug(C);

    ll count = 0;
    rep (i, length-2) {
        int n_c = S[i] - 'A';
        ll sum_idx = C[n_c][length].first - C[n_c][i+2].first;
        ll num_c = C[n_c][length].second - C[n_c][i+2].second;

        count += sum_idx - (i + 1) * num_c;
    }
    cout << count << '\n';

    return 0;
}