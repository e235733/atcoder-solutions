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

    int n;
    cin >> n;

    if (n == 1) {
        cout << "No" << '\n';
        return 0;
    }

    vector<int> A(n);
    rep (i, n) {
        cin >> A[i];
    }
    // 累積和
    vector<ll> sum_A(n*2);
    sum_A[0] = 0;
    rep (i, n) {
        sum_A[i+1] = sum_A[i] + A[i];
    }
    rep (i, n-1) {
        sum_A[n+i+1] = sum_A[n+i] + A[i];
    }
    debug(sum_A);
    
    // 合計が 10 の倍数でなければ終了
    if (sum_A[n] % 10 != 0) {
        cout << "No" << '\n';
        return 0;
    }
    ll size = sum_A[n] / 10;
    debug(size);

    // 尺取法で求める
    int l = 0;
    int r = 1;
    while (l != n) {
        ll sum = sum_A[r] - sum_A[l];
        debug(l, r, sum);
        if (sum == size) {
            cout << "Yes" << '\n';
            return 0;
        }
        else if (sum < size) {
            r++;
        }
        else {
            if (l + 1 == r) {
                l++;
                r++;
            }
            else {
                l++;
            }
        }
    }
    cout << "No" << '\n';

    return 0;
}