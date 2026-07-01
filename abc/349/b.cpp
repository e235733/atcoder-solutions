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
    vector<int> count(26, 0);

    rep (i, len) {
        count[s[i]-'a']++;
    }

    map<int, int> cc;
    rep (i, 26) {
        if (count[i] != 0) cc[count[i]]++;
    }

    debug(cc);
    for (auto [i, c] : cc) {
        if (c != 0 && c != 2) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}