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

    ll l, r;
    cin >> l >> r;

    ll left_l = l;
    int digit_l = 0;
    while (left_l != 0) {
        digit_l++;
        left_l /= 10;
    }
    ll left_r = r;
    int digit_r = 0;
    while (left_r != 0) {
        digit_r++;
        left_r /= 10;
    }
    debug(digit_l, digit_r);

    ll num_snake_digit_l = 0;
    for (int i=2; i!=digit_l+1; ++i) {
        ll m = 1;
        rep (_, digit_l-1) {
            m *= i;
        }
        debug(i, m);
        num_snake_digit_l += m;
    }
    debug(num_snake_digit_l);

    ll num_snake_digit_r = 0;
    for (int i=2; i!=digit_r+1; ++i) {
        ll m = 1;
        rep (_, digit_r-1) {
            m *= i;
        }
        debug(i, m);
        num_snake_digit_r += m;
    }
    debug(num_snake_digit_r);

    return 0;
}