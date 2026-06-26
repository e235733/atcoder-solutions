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

    string s, t;
    cin >> s >> t;

    int len_s = s.size();
    int len_t = t.size();
    debug(len_s, len_t);

    int j = 0;
    vector<int> result;
    rep (i, len_t) {
        if (j == len_s) {
            break;
        }
        debug(s[j], t[i]);
        if (s[j] == t[i]) {
            result.push_back(i+1);
            ++j;
        }
    }

    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}