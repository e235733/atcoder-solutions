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

    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll x = 0;
    ll pp = 0;
    rep (i, n) {
        ll cp = A[i] - pp;
        ll cn = n - i;
        if (cp * cn <= m) {
            x += cp;
            m -= cp * cn;
        }
        else {
            x += m / cn;
            m = -1;
            break;
        }
        pp = A[i];
    }

    if (m == -1) {
        cout << x << '\n';
    }
    else {
        cout << "infinite" << '\n';
    }

    return 0;
}