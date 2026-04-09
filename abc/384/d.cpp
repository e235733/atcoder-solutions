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

    ll n, s;
    cin >> n >> s;

    vector<ll> A(n);
    ll sum_a = 0;
    rep (i, n) {
        cin >> A[i];
        sum_a += A[i];
    }

    ll rem = s % sum_a;
    debug(s, sum_a, rem);
    if (rem == 0) {
        cout << "Yes" << '\n';
        return 0;
    }

    if (n == 1) {
        cout << "No" << '\n';
        return 0;
    }

    if (n == 2) {
        if (A[0] == rem || A[1] == rem) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
        return 0;
    }

    A.reserve(n * 2);
    rep (i, n) {
        A.push_back(A[i]);
    }

    // 尺取り法
    int l = 0;
    int r = 1;
    ll dp = A[0];
    while (r != n * 2 - 2) {
        if (dp == rem) {
            cout << "Yes" << '\n';
            debug(l, r);
            return 0;
        }
        else if (dp < rem) {
            dp += A[r];
            r++;
        }
        else {
            if (l == r - 1) {
                dp = A[r];
                l++;
                r++;
            }
            else {
                dp -= A[l];
                l++;
            }
        }
    }

    cout << "No" << '\n';

    return 0;
}