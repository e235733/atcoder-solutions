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

    int t;
    cin >> t;
    rep (_, t) {
        int n;
        cin >> n;
        ll sum_margin = 0;
        ll margin = 0;
        ll sum = 0;
        int prev;
        cin >> prev;
        prev = n - prev + 1;
        rep (i, n-1) {
            int current;
            cin >> current;
            current = n - current + 1;
            debug(sum_margin);
            debug(margin);
            debug(prev);
            debug(current);

            ll num_operation = 0;
            // 前のものに繋げればいい場合
            if (current <= prev + 1) {
                // すでに繋がっている場合
                if (current >= prev - 1) {
                    margin = sum_margin + prev + 1 - current;
                    sum_margin += margin;
                    prev = current;
                }
                else {
                    margin = sum_margin + 2;
                    sum_margin += margin;
                    num_operation = prev - 1 - current;
                    sum += num_operation;
                    prev--;
                }
            }
            else {
                // margin で賄える場合
                if (current - 1 - prev <= sum_margin) {
                    num_operation = current - 1 - prev;
                    sum_margin -= num_operation;
                    margin = sum_margin;
                    sum += num_operation;
                }
                else {
                    num_operation = sum_margin + (current - 1 - margin - prev) * (i + 1);
                    sum_margin = 0;
                    sum += num_operation;
                    margin = 0;
                }
                prev = current;
            }
            debug(num_operation);
        }

        cout << sum << endl;
    }

    return 0;
}