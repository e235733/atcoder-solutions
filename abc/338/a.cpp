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

    string s;
    cin >> s;
    int len = s.size();

    if (s[0]-'A' < 0 || s[0]-'A' >= 26) {
        cout << "No" << '\n';
        return 0;
    }

    rep (i, len-1) {
        if (s[i+1]-'a' < 0 || s[0]-'a' >= 26) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}