#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

    int c = 0;
    for (int r=1; true; ++r) {
        for (int i=1; i!=r+1; ++i) {
            for (int j=1; j!=i+1; ++j) {
                debug(j, i, r);
                ++c;
                if (c == n) {
                    ll ans = 0;
                    ll re = 0;
                    rep (_, j) {
                        re = re * 10 + 1;
                    }
                    ans += re;

                    rep (_, i-j) {
                        re = re * 10 + 1;
                    }
                    ans += re;

                    rep (_, r-i) {
                        re = re * 10 + 1;
                    }
                    ans += re;

                    cout << ans << '\n';

                    return 0;
                }
            }
        }
    }

    return 0;
}