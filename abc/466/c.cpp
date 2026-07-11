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

    int n;
    cin >> n;

    int clear = 1;
    int ans = 0;
    for (int i=1; i!=n+1; ++i) {
        for (int j=clear+1; j!=n+1; ++j) {
            cout << "? " << i << ' ' << j << '\n' << flush;
            string s;
            cin >> s;
            if (s == "Yes") {
                ++clear;
            }
            else if (s == "No") {
                ans += clear - i;
                break;
            }
            debug(clear);
        }
        if (clear == n) {
            ans += (n - i) * (n - i + 1) / 2;
            break;
        }
        debug(ans);

        if (clear == i) {
            ++clear;
        }
    }

    cout << "! " << ans << '\n';

    return 0;
}