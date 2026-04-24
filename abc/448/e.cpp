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

    int k, m;
    cin >> k >> m;
    ll mod = 10007 * m;

    vector<ll> C(k);
    vector<ll> L(k);
    rep (i, k) {
        cin >> C[i] >> L[i];
    }

    vector<ll> pow_keep(31);
    pow_keep[0] = 1;
    pow_keep[1] = 10;
    rep (i, 29) {
        pow_keep[i+2] = pow_keep[i+1] * pow_keep[i+1] % mod;
    }
    debug(pow_keep);

    vector<ll> rep_pow2(30);
    rep_pow2[0] = 1;
    rep (i, 29) {
        rep_pow2[i+1] = (rep_pow2[i] * pow_keep[i+1] + rep_pow2[i]) % mod;
    }
    debug(rep_pow2);

    ll q = 0;
    ll r = 1;
    ll left = L[0];
    int i = 0;
    while (left != 0) {
        if (left % 2 == 1) {
            q = (rep_pow2[i] * r + q) % mod;
            r = r * pow_keep[i+1] % mod;
        }
        left /= 2;
        ++i;
    }
    ll rem = q * C[0] % mod;
    rep (i, k-1) {
        debug(rem);
        left = L[i+1];
        q = 0;
        r = 1;
        int j = 0;
        while (left != 0) {
            if (left % 2 == 1) {
                q = (rep_pow2[j] * r + q) % mod;
                r = r * pow_keep[j+1] % mod;
                debug(j);
            }
            left /= 2;
            ++j;
        }
        debug(q, r);
        rem = (q * C[i+1] + r * rem) % mod;
    }

    cout << rem / m << '\n';

    return 0;
}