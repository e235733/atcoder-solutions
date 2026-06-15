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
    cin >> n;
    vector<string> s(n);
    rep (i, n) cin >> s[i];

    rep (i, n-2) {
        if (s[i+1] == "sweet" && s[i] == "sweet") {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}