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

    vector<int> p(26);
    rep (i, 26) {
        p[s[i]-'A'] = i;
    }
    debug(p);

    int result = 0;
    rep (i, 25) {
        result += abs(p[i+1]-p[i]);
    }
    cout << result << '\n';

    return 0;
}