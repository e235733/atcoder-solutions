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

    rep (i, n) {
        rep (j, n) {
            int a;
            cin >> a;
            if (a == 1 && i != j) {
                cout << j+1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}