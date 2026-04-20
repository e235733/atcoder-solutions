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
    string s;
    cin >> n >> s;

    vector<ll> sum(n+1, 0);
    rep(i, n) {
        ll v = s[i] - '0';
        sum[i+1] = sum[i] + v * (i + 1);
    }
    debug(sum);

    rep (i, n) {
        sum[n-i-1] += sum[n-i] / 10;
        sum[n-i] %= 10; 
    }
    if (sum[0] != 0) {
        cout << sum[0];
    }
    for (int i=1; i!=n+1; ++i) {
        cout << sum[i];
    }
    cout << '\n';

    return 0;
}