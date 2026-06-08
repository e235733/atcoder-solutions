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
        vector<int> p(n);
        rep (i, n) cin >> p[i];

        int count = 0;
        bool perfect = true;
        rep (i, n) {
            if (p[i] != i + 1) {
                perfect = false;
                break;
            }
            count += n - i - 1;
            count %= 998244353;
        }

        if (perfect) {
            count++;
            count %= 998244353;
        }

        cout << count << '\n';
    }

    return 0;
}