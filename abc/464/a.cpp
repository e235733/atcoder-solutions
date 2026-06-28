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

    int ce = 0;
    int cw = 0;
    for (char c : s) {
        if (c == 'E') ce++;
        else cw++;
    }

    if (ce > cw) cout << "East" << '\n';
    else cout << "West" << '\n';

    return 0;
}