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
    
    int x = 10000, y = 10000;
    rep (i, n) {
        int a, b;
        string s;
        cin >> a >> b >> s;

        if (s == "keep") {
            x -= b;
        }
        else if (s == "take") {
            x -= a;
        }

        y -= a;
    }

    cout << y - x << '\n';

    return 0;
}