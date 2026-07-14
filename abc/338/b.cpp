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

    vector<int> count(26, 0);
    for (char c : s) {
        ++count[c-'a'];
    }

    int mc = *max_element(count.begin(), count.end());
    rep (i, 26) {
        if (count[i] == mc) {
            cout << (char)(i+'a') << '\n';
            return 0;
        }
    }

    return 0;
}