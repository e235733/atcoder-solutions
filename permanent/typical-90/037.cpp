#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

class RangeMax {
public:
    int size_ = 1;
    vector<ll> dat;

    void init(int sz) {
        while (size_ <= sz) size_ *= 2;
        dat.resize(size_ * 2, -(1LL << 60));
    }

    void update(int pos, ll x) {
        pos += size_;
        dat[pos] = x;
        while (pos >= 2) {
            pos >>= 1;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    ll query_(int l, int r, int a, int b, int u) {
        if (l <= a && b <= r) return dat[u];
        if (r <= a || b <= l) return -(1LL << 60);

        ll v1 = query_(l, r, a, (a + b) >> 1, u * 2);
        ll v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
        return max(v1, v2);
    }

    ll query(int l, int r) {
        return query_(l, r, 0, size_, 1);
    }
};

ll w, n;
ll L[1 << 18], R[1 << 18], V[1 << 18];
ll dp[509][10009];
RangeMax Z[509];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> w >> n;
    rep (i, n) {
        cin >> L[i+1] >> R[i+1] >> V[i+1];
    }

    rep (i, n+1) {
        rep (j, w+1) dp[i][j] = -(1LL << 60);
        Z[i].init(w+2);
    }
    dp[0][0] = 0;
    Z[0].update(0, 0);

    rep (i, n) {
        rep (j, w+1) dp[i+1][j] = dp[i][j];
        rep (j, w+1) {
            int cl = max(0, j - (int)R[i+1]);
            int cr = max(0, j - (int)L[i+1] + 1);
            if (cl == cr) continue;

            ll val = Z[i].query(cl, cr);
            if (val != -(1LL << 60)) {
                dp[i+1][j] = max(dp[i+1][j], val + V[i+1]);
            }
        }

        rep (j, w+1) Z[i+1].update(j, dp[i+1][j]);
    }

    if (dp[n][w] == -(1LL << 60)) cout << -1 << '\n';
    else cout << dp[n][w] << '\n';

    return 0;
}