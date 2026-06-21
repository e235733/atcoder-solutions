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

    string s, t;
    cin >> s >> t;

    if (s == "AtCoder" && t == "Land") cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}