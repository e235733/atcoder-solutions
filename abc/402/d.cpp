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

    int n, m;
    cin >> n >> m;
    debug(n, m);

    // n で割ったあまりとその数
    map<int, int> remainder;
    rep (i, m) {
        int a, b;
        cin >> a >> b;
        int rem = (a + b) % n;
        remainder[rem]++;
    }
    debug(remainder);

    // すべての組み合わせの数
    ll num_all_pair = 1LL * m * (m - 1) / 2;
    debug(num_all_pair);
    ll result = num_all_pair;
    for (auto [_, num_rem] : remainder) {
        ll num_pair = 1LL * num_rem * (num_rem - 1) / 2;
        result -= num_pair;
    }

    cout << result << endl;

    return 0;
}