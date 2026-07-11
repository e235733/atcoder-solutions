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

    vector<int> cc(26, 0);
    for (char c : s) {
        ++cc[c-'a'];
    }

    rep (i, 26) {
        if (cc[i] == 1) {
            int j = 0;
            while (true) {
                if (s[j]-'a' == i) {
                    cout << j+1 << '\n';
                    return 0;
                }
                ++j;
            }
        }
    }

    return 0;
}