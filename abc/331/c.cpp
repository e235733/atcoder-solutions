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

    int n;
    cin >> n;
    vector<ll> A(n);
    rep (i, n) cin >> A[i];

    vector<ll> B = A;
    sort(B.begin(), B.end());
    debug(B);

    vector<ll> S(n+1);
    S[0] = 0;
    rep (i, n) S[i+1] = S[i] + B[i];
    debug(S);

    rep (i, n) {
        ll a = A[i];
        //debug(i, a);

        int ok = n;
        int ng = 0;
        while (ng + 1 < ok) {
            int mid = (ok + ng) / 2;
            if (B[mid] > a) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }
        //debug(ok);

        cout << S[n] - S[ok] << ' ';
    }
    cout << '\n';

    return 0;
}