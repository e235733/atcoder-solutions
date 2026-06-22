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

    string s;
    cin >> s;
    int len = s.size();
    int cu = 0;
    rep (i, len) {
        if (s[i] - 'A' >= 0 && s[i] - 'A' < 26) cu++;
    }

    if (cu > len - cu) {
        rep (i, len) {
            if (s[i] - 'A' < 0 || s[i] - 'A' >= 26) cout << char(s[i] - 'a' + 'A');
            else cout << s[i];
        }
    }
    else {
        rep (i, len) {
            if (s[i] - 'A' >= 0 && s[i] - 'A' < 26) cout << char(s[i] - 'A' + 'a');
            else cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}