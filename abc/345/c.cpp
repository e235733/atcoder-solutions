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

    vector<int> C(26, 0);
    C[s[0]-'a']++;

    ll ans = 0;
    for (int i=1; i!=len; ++i) {
        debug(s[i]);
        int dc = i - C[s[i]-'a'];
        ans += dc;

        C[s[i]-'a']++;
        debug(ans);
    }

    rep (i, 26) {
        if (C[i] > 1) {
            ans++;
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}