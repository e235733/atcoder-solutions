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

    vector<ll> p10(19);
    p10[0] = 1;
    rep (i, 18) {
        p10[i+1] = p10[i] * 10;
    }
    p10[0] = 0;

    ll n;
    cin >> n;
    ll d = -1;
    ll rp = -1;
    rep (i, 18) {
        if (p10[i]*2 < n && n <= p10[i+1]*2) {
            d = i;
            rp = n - p10[i]*2;
            break;
        }
    }
    debug(d, rp);
    if (d == 0) rp--;

    if (rp > p10[d+1] - p10[d]) {
        string t = to_string(rp+p10[d]*2-p10[d+1]);
        cout << t;
        reverse(t.begin(), t.end());
        cout << t << '\n';
    }
    else {
        string t = to_string(rp+p10[d]);
        cout << t;
        t.pop_back();
        reverse(t.begin(), t.end());
        cout << t << '\n';
    }

    return 0;
}