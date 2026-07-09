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
    int i = 0;
    while (s[i] != '|') {
        cout << s[i];
        ++i;
    }
    ++i;
    while (s[i] != '|') ++i;
    ++i;

    while (i != len) {
        cout << s[i];
        ++i;
    }
    cout << '\n';

    return 0;
}