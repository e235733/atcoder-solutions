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

    ll divider = 1;
    rep (_, 9) {
        divider *= 10;
    }
    divider += 7;

    ll l, r;
    cin >> l >> r;
    debug(l, r);

    ll left_l = l;
    ll min_digit = 0;
    while (left_l != 0) {
        min_digit++;
        left_l /= 10;
    }
    ll left_r = r;
    ll max_digit = 0;
    while (left_r != 0) {
        max_digit++;
        left_r /= 10;
    }
    debug(min_digit, max_digit);

    if (min_digit == max_digit) {
        ll result;
        if ((l + r) % 2 == 0) {
            result = ((l + r) / 2 % divider) * ((r - l + 1) % divider) % divider * min_digit % divider;
        }
        else {
            result = ((l + r) % divider) * ((r - l + 1) / 2 % divider) % divider * min_digit % divider;
        }
        cout << result << '\n';
        return 0;
    }

    else {
        ll result = 0;

        // 最小桁数での総和
        ll max_min_digit = 1;
        rep (_, min_digit) {
            max_min_digit *= 10;
        }
        max_min_digit--;
        debug(max_min_digit);
        ll min_sum;
        if ((l + max_min_digit) % 2 == 0) {
            min_sum = ((l + max_min_digit) / 2 % divider) * ((max_min_digit - l + 1) % divider) % divider * min_digit;
        }
        else {
            min_sum = ((l + max_min_digit) % divider) * ((max_min_digit - l + 1) / 2 % divider) % divider * min_digit;
        }
        debug(min_sum);
        result += min_sum;

        // 最大桁数での総和
        ll min_max_digit = 1;
        rep (_, max_digit - 1) {
            min_max_digit *= 10;
        }
        debug(min_max_digit);
        ll max_sum;
        if ((min_max_digit + r) % 2 == 0) {
            max_sum = ((min_max_digit + r) / 2 % divider) * ((r - min_max_digit + 1) % divider) % divider * max_digit;
        }
        else {
            max_sum = ((min_max_digit + r) % divider) * ((r - min_max_digit + 1) / 2 % divider) % divider * max_digit;
        }
        debug(max_sum);
        result += max_sum;

        // 中間での総和
        ll mid_sum = 0;
        for (ll digit=min_digit+1; digit!=max_digit; ++digit) {
            debug(digit);
            ll min = 1;
            rep (_, digit-1) {
                min *= 10;
            }
            ll max = 1;
            rep (_, digit) {
                max *= 10;
            }
            max--;
            debug(min, max);

            ll sum;
            if ((min + max) % 2 == 0) {
                sum = ((min + max) / 2 % divider) * ((max - min + 1) % divider) % divider * digit;
            }
            else {
                sum = ((min + max) % divider) * ((max - min + 1) / 2 % divider) % divider * digit;
            }
            debug(sum);
            mid_sum += sum;
        }
        debug(mid_sum);
        result += mid_sum;

        result %= divider;
        cout << result << '\n';
    }


    return 0;
}