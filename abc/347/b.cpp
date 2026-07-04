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
    int n = s.size();

    set<string> sub;
    rep (i, n) {
        string t = "";
        for (int j=i; j!=n; ++j) {
            t.push_back(s[j]);
            sub.insert(t);
        }
    }

    debug(sub);
    cout << sub.size() << '\n';

    return 0;
}