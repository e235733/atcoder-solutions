#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#ifndef LOCAL
#define debug(...)
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    ll n, k;
    cin >> n >> k;

    // それぞれの値が何回目に出たか
    vector<ll> when(100000, -1);
    // それぞれの回に何が出たか
    vector<ll> what(100000);
    what[0] = n;
    // ループを調べ、２つの同じ値が登場する回を記録
    ll l = -1;
    ll r = -1;
    rep (i, k) {
        // 次の値を求める
        ll m = what[i];
        ll current = m;
        while (m != 0) {
            current += m % 10;
            m /= 10;
        }
        current %= 100000;
        debug(i, current);

        if (when[current] != -1) {
            l = when[current];
            r = i + 1;
            break;
        }
        when[current] = i + 1;
        what[i+1] = current;
    }
    debug(l, r);

    // ループしなかった場合
    if (l == -1 && r == -1) {
        cout << what[k] << '\n';
        return 0;
    }

    ll mod = r - l;
    // 実質的な操作回数
    ll j = (k - l) % mod + l;
    debug(j);

    cout << what[j] << '\n';

    return 0;
}