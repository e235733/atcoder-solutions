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

    int t;
    cin >> t;
    rep (_, t) {
        int n;
        cin >> n;

        int s_or = 0;
        int s_xor = 0;
        rep (i, n) {
            int a;
            cin >> a;
            s_or |= a;
            s_xor ^= a;
        }
        if (s_or != s_xor) {
            cout << "Alice" << '\n';
        }
        else {
            cout << "Bob" << '\n';
        }
    }

    return 0;
}