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
    
    if (n % 2 == 0) {
        cout << "No" << '\n';
        return 0;
    }

    int mid = (n + 1) / 2 - 1;
    debug(mid);
    rep (i, n) {
        debug(i, s[i]);
        if (i < mid) {
            if (s[i] != '1') {
                cout << "No" << '\n';
                return 0;
            }
        }
        else if (i == mid) {
            if (s[i] != '/') {
                cout << "No" << '\n';
                return 0;
            }
        }
        else {
            if (s[i] != '2') {
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    cout << "Yes" << '\n';

    return 0;
}