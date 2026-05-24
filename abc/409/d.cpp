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
        string s;
        cin >> n >> s;

        int l = -1;
        rep (i, n-1) {
            if (s[i]-s[i+1] > 0) {
                l = i+1;
                break;
            }
        }
        debug(l);

        if (l == -1) {
            cout << s << '\n';
            continue;
        }

        int r = -1;
        for (int i=l+1; i!=n; ++i) {
            if (s[i]-s[l-1] > 0) {
                r = i;
                break;
            }
        }

        if (r == -1) {
            r = n;
        }
        debug(r);

        rep (i, l-1) {
            cout << s[i];
        }
        for (int i=l; i!=r; ++i) {
            cout << s[i];
        }
        cout << s[l-1];
        for (int i=r; i!=n; ++i) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}