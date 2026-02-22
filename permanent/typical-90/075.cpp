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
    
    ll n;
    cin >> n;

    ll rem = n;
    int count = 0;
    for (ll i=2; i*i<=n; ++i) {
        while (rem % i == 0) {
            count++;
            rem /= i;
            debug(i, rem);
        }
    }
    if (rem != 1) {
        count++;
    }
    debug(count);

    // log_2(count) 以上最小の整数を求める
    int result = 0;
    int m = 1;
    while (m < count) {
        m *= 2;
        result++;
    }
    cout << result << '\n';

    return 0;
}