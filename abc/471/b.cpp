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

    map<string, int> M;
    rep (i, n) {
        string s;
        cin >> s;
        int len = s.size();
        rep (j, len) {
            if (s[j] - 'A' >= 0 && s[j] - 'A' < 26) {
                s[j] += 'a' - 'A'; 
            }
        }
        ++M[s];
    }
    debug(M);

    int ans = 0;
    for (auto [s, c] : M) {
        ans = max(ans, c);
    }

    cout << ans << '\n';

    return 0;
}