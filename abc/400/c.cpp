#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

// 二分探索で平方根を求める
ll my_sqrt(ll x) {
    ll ok = 0;
    ll ng = 1000000000;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid <= x) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ll n;
    cin >> n;
    debug(n);

    // 良い整数を数え上げる
    ll num_good = 0;
    // 奇数番目の和
    if (n >= 2) {
        num_good += my_sqrt(n / 2);
    } 

    // 偶数番目の和
    if (n >= 4) {
        num_good += my_sqrt(n / 4);
    }
    
    cout << num_good << endl;

    return 0;
}