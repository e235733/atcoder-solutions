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

    int n, d;
    cin >> n >> d;

    debug(n, d);
    // 除数が 0 なら数値の被りを数え上げる
    if (d == 0) {
        map<int, int> count;
        rep (i, n) {
            int a;
            cin >> a;

            count[a]++;
        }
        debug(count);

        int result = 0;
        for (auto c : count) {
            result += c.second - 1;
        }

        cout << result << endl;

        return 0;
    }

    // 余りごとの商
    vector<map<int, int>> remainder(d);
    rep (i, n) {
        int a;
        cin >> a;
        // あまりと商を求める
        int r = a % d;
        int q = a / d;
        remainder[r][q]++;
    }
    debug(remainder);

    int result = 0;

    for (auto r : remainder) {
        debug(r);
        // 直前の値。最初は連続にならないようにする
        int prev = -1000000000;
        int num_prev_q = 0;
        bool is_consecutively = false;
        // 合計の最小値を動的計画法で求める
        int dp0 = 0;
        int dp1 = 0;
        int dp2 = 0;
        for (auto q : r) {
            int val_q = q.first;
            int num_q = q.second;
            debug(val_q, num_q);
            // 継続中の場合
            if (is_consecutively) {
                if (val_q - prev == 1) {
                    int min_dp = min(dp0, dp2);
                    dp2 = dp1 + num_q;
                    dp0 = min_dp + num_q;
                    dp1 = min_dp;
                }
                // 連続が終了する
                else {
                    is_consecutively = false;
                    // 小さい方を加算
                    result += min(dp0, min(dp1, dp2));
                    dp0 = 0;
                    dp1 = 0;
                    dp2 = 0;
                }
            }
            else {
                // 2番目のまとまりとして連続開始
                if (val_q - prev == 1) {
                    is_consecutively = true;
                    dp0 = num_prev_q + num_q;
                    dp1 = num_prev_q;
                    dp2 = num_q;
                }
            }
            debug(is_consecutively);
            debug(dp0, dp1, dp2);
            prev = val_q;
            num_prev_q = num_q;
        }
        // 最後まで連続していたときの加算
        result += min(dp0, min(dp1, dp2));
    }

    cout << result << endl;

    return 0;
}