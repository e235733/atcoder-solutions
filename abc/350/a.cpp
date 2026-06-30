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

    int n = 0;
    n += (s[3] - '0') * 100;
    n += (s[4] - '0') * 10;
    n += (s[5] - '0');

    if (n < 350 && n > 0 && n != 316) {
        cout << "Yes" << '\n';
    }
    else cout << "No" << '\n';

    return 0;
}